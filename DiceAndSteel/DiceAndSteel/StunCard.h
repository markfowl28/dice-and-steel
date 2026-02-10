#pragma once
#include "Card.h"
#include "Player.h"

class StunCard : public Card {
public:
	explicit StunCard(int turns);

	void play(
		Player& self,
		Player& opponent
	) override;

private:
	int turns;
};