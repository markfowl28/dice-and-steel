#pragma once
#include "Dice.h"
#include "Combat.h"
#include "Resolution.h"

struct TurnSnapshot {
	DiceFace diceRoll;

	CombatIntent attackerIntent;
	CombatIntent defenderIntent;

	ResolutionResult result;
};


