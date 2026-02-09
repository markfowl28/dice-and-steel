#include <memory>
#include "AttackBuffCard.h"
#include "BuffAttackEffect.h"
#include "Player.h"

AttackBuffCard::AttackBuffCard(int turns)
	: turns(turns) {}

void AttackBuffCard::play(
	Player& self,
	Player& opponent
) {
	self.applyStatus(
		std::make_unique<BuffAttackEffect>(turns)
	);
}