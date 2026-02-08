#include "TurnSnapshot.h"
#include "GameEngine.h"
#include "Dice.h"
#include "Combat.h"
#include "Resolution.h"
#include <iostream>

TurnSnapshot buildTurn() {
	TurnSnapshot snap;

	snap.diceRoll = rollDie();

	snap.attackerIntent = mapDiceToIntent(snap.diceRoll, Role::Attacker);
	snap.defenderIntent = mapDiceToIntent(snap.diceRoll, Role::Defender);

	snap.result = resolveCombat(
		snap.attackerIntent,
		snap.defenderIntent
		);

	return snap;
}

void GameEngine::runTurn() {
	TurnSnapshot snap = buildTurn();

	std::cout << "Roll: " << toString(snap.diceRoll) << "\n";
	std::cout << "Attacker Intent: " << toString(snap.attackerIntent) << "\n";
	std::cout << "Defender Intent: " << toString(snap.defenderIntent) << "\n";
	std::cout << "Damage -> Defender: " << snap.result.damageToDefender
		<< " | Attacker: " << snap.result.damageToAttacker << "\n\n";
}