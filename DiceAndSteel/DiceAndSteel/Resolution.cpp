#include "Resolution.h"
#include "Combat.h"
#include "Player.h"

ResolutionResult resolveCombat(
	CombatIntent attackerIntent,
	CombatIntent defenderIntent,
	Player& attacker,
	Player& defender
) {
	ResolutionResult result;

	int attackPower = 0;
	int defensePower = 0;
	int counterPower = 0;

	//Attacker Intent
	if (attackerIntent == CombatIntent::Attack) {
		attackPower += 1;
	}

	if (attackerIntent == CombatIntent::Critical) {
		attackPower += 2;
	}

	//Defender Intent
	if (defenderIntent == CombatIntent::Defend) {
		defensePower += 1;
	}

	if (defenderIntent == CombatIntent::Counter) {
		counterPower += 1;
	}

	int finalDamage = (attackPower + attacker.bonusAttack) - (defensePower + defender.bonusDefense);
	if (finalDamage < 0) finalDamage = 0;

	result.damageToDefender = finalDamage;
	result.damageToAttacker = counterPower;

	return result;
}