#include <memory>
#include "DebuffAttackEffect.h"
#include "AttackDebuffCard.h"
#include "Player.h"

AttackDebuffCard::AttackDebuffCard(int turns)
	: turns(turns) {}

void AttackDebuffCard::play(
	Player& self,
	Player& opponent
) {
	opponent.applyStatus(
		std::make_unique<DebuffAttackEffect>(turns)
	);
}