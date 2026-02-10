#include <iostream>
#include "TurnSnapshot.h"
#include "GameEngine.h"
#include "Dice.h"
#include "Combat.h"
#include "Resolution.h"
#include "Player.h"
#include "TurnPhase.h"

TurnSnapshot buildTurn(Player& attacker, Player& defender) {
	TurnSnapshot snap;

	snap.diceRoll = rollDie();

	if (attacker.isStunned) {
		snap.attackerIntent = CombatIntent::None;
	}
	else {
		snap.attackerIntent = mapDiceToIntent(snap.diceRoll, Role::Attacker);
	}

	if (defender.isStunned) {
		snap.defenderIntent = CombatIntent::None;
	} else {
		snap.defenderIntent = mapDiceToIntent(snap.diceRoll, Role::Defender);
	}

	snap.result = resolveCombat(
		snap.attackerIntent,
		snap.defenderIntent,
		attacker,
		defender
		);

	return snap;
}

GameEngine::GameEngine() {
	attacker.health = 10;
	defender.health = 10;
}

void GameEngine::runGame() {
	int turn = 1;

	while (attacker.isAlive() && defender.isAlive()) {
		attacker.bonusAttack = 0;
		defender.bonusAttack = 0;

		attacker.bonusDefense = 0;
		defender.bonusDefense = 0;

		attacker.isStunned = false;
		defender.isStunned = false;

		std::cout << "\n--- Turn " << turn++ << " ---\n";

		attacker.processStatusEffects(TurnPhase::Start, defender);
		defender.processStatusEffects(TurnPhase::Start, attacker);

		attacker.processStatusEffects(TurnPhase::Resolution, defender);
		defender.processStatusEffects(TurnPhase::Resolution, attacker);

		TurnSnapshot snap = buildTurn(attacker, defender);

		attacker.processStatusEffects(TurnPhase::End, defender);
		defender.processStatusEffects(TurnPhase::End, attacker);

		defender.takeDamage(snap.result.damageToDefender);
		attacker.takeDamage(snap.result.damageToAttacker);

		std::cout << "Attacker Bonus Damage: " << attacker.bonusAttack << " | " << "Attacker Bonus Defense: " << attacker.bonusDefense << "\n";
		std::cout << "Defender Bonus Damage: " << defender.bonusAttack << " | " << "Defender Bonus Defense: " << defender.bonusDefense << "\n";

		std::cout << "Roll: " << toString(snap.diceRoll) << "\n";
		std::cout << "Attacker intent: " << toString(snap.attackerIntent) << "\n";
		std::cout << "Defender intent: " << toString(snap.defenderIntent) << "\n";

		std::cout << "Damage -> Defender: " << snap.result.damageToDefender
			<< " | Attacker: " << snap.result.damageToAttacker << "\n";

		std::cout << "Health -> Attacker: " << attacker.health
			<< " | Defender: " << defender.health << "\n";
	}

	std::cout << "\n=== Game Over ===\n";
	if (attacker.isAlive()) {
		std::cout << "Attacker wins!\n";
	}
	else {
		std::cout << "Defender wins!\n";
	}
}