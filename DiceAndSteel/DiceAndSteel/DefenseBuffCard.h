#pragma once
#include "Card.h"
#include "Player.h"
#include <string>

class DefenseBuffCard : public Card {
public:
	explicit DefenseBuffCard(int turns);

	void play(
		Player& self,
		Player& opponent
	) override;

	std::string name() const override { return "Defense Buff"; }

	std::string description() const override { return "+1 defense for 2 turns"; }

private:
	int turns;
};
