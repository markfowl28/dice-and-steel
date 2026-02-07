#pragma once
#include <string>
#include "Dice.h"

enum class Role {
	Attacker,
	Defender
};

enum class CombatIntent {
	Attack,
	Defend,
	Counter,
	None
};

CombatIntent mapDiceToIntent(DiceFace face, Role role);

std::string toString(Role role);
std::string toString(CombatIntent intent);
