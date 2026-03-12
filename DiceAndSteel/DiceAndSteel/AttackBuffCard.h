#pragma once
#include "Card.h"
#include "Player.h"
#include <string>

class AttackBuffCard : public Card {
public:
	explicit AttackBuffCard(int turns);

	void play(
		Player& self,
		Player& opponent
	) override;

	std::string name() const override { return "Attack Buff"; }

	std::string description() const override { return "+1 attack for 2 turns"; }

private:
	int turns;
};
