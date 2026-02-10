#include <memory>
#include "StunCard.h"
#include "StunEffect.h"
#include "Player.h"

StunCard::StunCard(int turns)
	: turns(turns) {}

void StunCard::play(
	Player& self,
	Player& opponent
) {
	opponent.applyStatus(
		std::make_unique<StunEffect>(turns)
	);
}