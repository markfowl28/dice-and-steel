#pragma once
#include "Card.h"
#include "Player.h"

class AttackBuffCard : public Card {
public:
	explicit AttackBuffCard(int turns);

	void play(
		Player& self,
		Player& opponent
	) override;

private:
	int turns;
};
