#include "BuffDefenseEffect.h"
#include "Player.h"
#include "TurnPhase.h"

BuffDefenseEffect::BuffDefenseEffect(int turns)
	: remainingTurns(turns) {}

void BuffDefenseEffect::onPhase(
	TurnPhase phase,
	Player& self,
	Player& opponent
) {
	if (phase == TurnPhase::Resolution) {
		self.bonusDefense += 1;
		remainingTurns--;
	}
}

bool BuffDefenseEffect::isExpired() const {
	return remainingTurns <= 0;
}