#pragma once
#include "Card.h"
#include "Player.h"

class AttackDebuffCard : public Card {
public:
	explicit AttackDebuffCard(int turns);

	void play(
		Player& self,
		Player& opponent
	) override;

private:
	int turns;
};


