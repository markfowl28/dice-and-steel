#pragma once
#include "Card.h"
#include "Player.h"

class DefenseDebuffCard : public Card {
public:
	explicit DefenseDebuffCard(int turns);

	void play(
		Player& self,
		Player& opponent
	) override;

private:
	int turns;
};


