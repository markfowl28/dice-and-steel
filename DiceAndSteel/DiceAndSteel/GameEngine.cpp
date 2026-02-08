#include "TurnSnapshot.h"
#include "GameEngine.h"
#include "Dice.h"
#include "Combat.h"
#include "Resolution.h"
#include <iostream>
#include "Player.h"
#include <memory>
#include "TurnPhase.h"
#include "BuffAttackEffect.h"
#include "BuffDefenseEffect.h"
#include "DebuffAttackEffect.h"
#include "DebuffDefenseEffect.h"

TurnSnapshot buildTurn(Player& attacker, Player& defender) {
	TurnSnapshot snap;

	snap.diceRoll = rollDie();

	snap.attackerIntent = mapDiceToIntent(snap.diceRoll, Role::Attacker);
	snap.defenderIntent = mapDiceToIntent(snap.diceRoll, Role::Defender);

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

		defender.applyStatus(
			std::make_unique<DebuffDefenseEffect>(1)
		);

		defender.applyStatus(
			std::make_unique<BuffDefenseEffect>(1)
		);

		std::cout << "\n--- Turn " << turn++ << " ---\n";

		attacker.processStatusEffects(TurnPhase::Start, defender);
		defender.processStatusEffects(TurnPhase::Start, attacker);

		attacker.processStatusEffects(TurnPhase::Resolution, defender);
		defender.processStatusEffects(TurnPhase::Resolution, attacker);

		std::cout << "Defense bonus: " << defender.bonusDefense << "\n";

		TurnSnapshot snap = buildTurn(attacker, defender);

		attacker.processStatusEffects(TurnPhase::End, defender);
		defender.processStatusEffects(TurnPhase::End, attacker);

		defender.takeDamage(snap.result.damageToDefender);
		attacker.takeDamage(snap.result.damageToAttacker);

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