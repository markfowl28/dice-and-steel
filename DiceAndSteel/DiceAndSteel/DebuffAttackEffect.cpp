#include "DebuffAttackEffect.h"
#include "TurnPhase.h"
#include "Player.h"

DebuffAttackEffect::DebuffAttackEffect(int turns)
	: remainingTurns(turns) {}

void DebuffAttackEffect::onPhase(
	TurnPhase phase,
	Player& self,
	Player& opponent
) {
	if (phase == TurnPhase::Resolution) {
		self.bonusAttack -= 1;
		remainingTurns--;
	}
}

bool DebuffAttackEffect::isExpired() const {
	return remainingTurns <= 0;
}