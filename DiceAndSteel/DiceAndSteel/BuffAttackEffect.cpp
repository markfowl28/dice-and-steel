#include "BuffAttackEffect.h"
#include "Player.h"
#include "TurnPhase.h"

BuffAttackEffect::BuffAttackEffect(int turns)
	: remainingTurns(turns) {}

void BuffAttackEffect::onPhase(
	TurnPhase phase,
	Player& self,
	Player& opponent
) {
	if (phase == TurnPhase::Resolution) {
		self.bonusAttack += 1;
		remainingTurns--;
	}
}

bool BuffAttackEffect::isExpired() const {
	return remainingTurns <= 0;
}