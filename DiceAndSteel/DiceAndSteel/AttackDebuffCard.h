#pragma once
#include "Card.h"
#include "Player.h"
#include <string>

class AttackDebuffCard : public Card {
public:
	explicit AttackDebuffCard(int turns);

	void play(
		Player& self,
		Player& opponent
	) override;

	std::string name() const override { return "Attack Debuff"; }

	std::string description() const override { return "-1 attack for 1 turn"; }

private:
	int turns;
};


