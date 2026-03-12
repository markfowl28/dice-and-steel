#pragma once
#include "Card.h"
#include "Player.h"
#include <string>

class PoisonCard : public Card {
public: 
	explicit PoisonCard(int turns, int damage);

	void play(
		Player& self,
		Player& opponent
	) override;

	std::string name() const override { return "Poison"; }

	std::string description() const override { return "-1 health for 2 turns"; }

private:
	int turns;
	int damage;
};
