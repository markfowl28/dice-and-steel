#include <memory>
#include "DefenseDebuffCard.h"
#include "DebuffDefenseEffect.h"
#include "Player.h"

DefenseDebuffCard::DefenseDebuffCard(int turns)
	: turns(turns) {}

void DefenseDebuffCard::play(
	Player& self,
	Player& opponent
) {
	opponent.applyStatus(
		std::make_unique<DebuffDefenseEffect>(turns)
	);
}