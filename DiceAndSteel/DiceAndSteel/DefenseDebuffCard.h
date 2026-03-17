#pragma once
#include "Card.h"
#include "Player.h"
#include <string>

class DefenseDebuffCard : public Card {
public:
	explicit DefenseDebuffCard(int turns);

	void play(
		Player& self,
		Player& opponent
	) override;

	std::string name() const override { return "Defense Debuff"; }

	std::string description() const override { return "-1 defense for 1 turn"; }

private:
	int turns;
};


