#pragma once
#include "Card.h"
#include "Player.h"

class DefenseBuffCard : public Card {
public:
	explicit DefenseBuffCard(int turns);

	void play(
		Player& self,
		Player& opponent
	) override;

private:
	int turns;
};
