#include <memory>
#include "PoisonCard.h"
#include "PoisonEffect.h"
#include "Player.h"

PoisonCard::PoisonCard(int turns, int damage)
	: turns(turns), damage(damage) {}

void PoisonCard::play(
	Player& self,
	Player& opponent
) {
	opponent.applyStatus(
		std::make_unique<PoisonEffect>(turns, damage)
	);
}

