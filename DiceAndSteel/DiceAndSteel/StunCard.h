#pragma once
#include "Card.h"
#include "Player.h"
#include <string>

class StunCard : public Card {
public:
	explicit StunCard(int turns);

	void play(
		Player& self,
		Player& opponent
	) override;

	std::string name() const override { return "Stun"; }

	std::string description() const override { return "Skip next turn"; }

private:
	int turns;
};