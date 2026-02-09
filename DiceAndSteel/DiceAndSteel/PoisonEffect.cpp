#include "PoisonEffect.h"
#include "Player.h"
#include "TurnPhase.h"

PoisonEffect::PoisonEffect(int turns, int damage)
	: remainingTurns(turns), damagePerTurn(damage) {}

void PoisonEffect::onPhase(
	TurnPhase phase,
	Player& self,
	Player& opponent
) {
	if (phase == TurnPhase::End) {
		self.takeDamage(damagePerTurn);
		remainingTurns--;
	}
}

bool PoisonEffect::isExpired() const {
	return remainingTurns <= 0;
}