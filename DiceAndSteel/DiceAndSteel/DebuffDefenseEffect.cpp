#include "DebuffDefenseEffect.h"
#include "TurnPhase.h"
#include "Player.h"

DebuffDefenseEffect::DebuffDefenseEffect(int turns)
	: remainingTurns(turns) {}

void DebuffDefenseEffect::onPhase(
	TurnPhase phase,
	Player& self,
	Player& opponent
) {
	if (phase == TurnPhase::Resolution) {
		self.bonusDefense -= 1;
		remainingTurns--;
	}
}

bool DebuffDefenseEffect::isExpired() const {
	return remainingTurns <= 0;
}