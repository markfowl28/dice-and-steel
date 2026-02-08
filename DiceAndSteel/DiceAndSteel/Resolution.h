#pragma once
#include "Combat.h"
#include "Player.h"

struct ResolutionResult {
	int damageToDefender = 0;
	int damageToAttacker = 0;
};

ResolutionResult resolveCombat(
	CombatIntent attackerIntent,
	CombatIntent defenderIntent,
	Player& attacker,
	Player& defender
);