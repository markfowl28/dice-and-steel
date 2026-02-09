#include <memory>
#include "DefenseBuffCard.h"
#include "BuffDefenseEffect.h"
#include "Player.h"

DefenseBuffCard::DefenseBuffCard(int turns)
	: turns(turns) {}

void DefenseBuffCard::play(
	Player& self,
	Player& opponent
) {
	self.applyStatus(
		std::make_unique<BuffDefenseEffect>(turns)
	);
}