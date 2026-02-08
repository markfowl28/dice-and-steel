#pragma once
#include "Combat.h"

struct ResolutionResult {
	int damageToDefender = 0;
	int damageToAttacker = 0;
};

ResolutionResult resolveCombat(
	CombatIntent attackerIntent,
	CombatIntent defenderIntent
);