#include "StunEffect.h"
#include "Player.h"
#include "TurnPhase.h"

StunEffect::StunEffect(int turns)
	: remainingTurns(turns) {}

void StunEffect::onPhase(
	TurnPhase phase,
	Player& self,
	Player& opponent
) {
	if (phase == TurnPhase::Start) {
		self.isStunned = true;
		remainingTurns--;
	}
}

bool StunEffect::isExpired() const {
	return remainingTurns <= 0;
}