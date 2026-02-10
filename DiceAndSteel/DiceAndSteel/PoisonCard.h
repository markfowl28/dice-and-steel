#pragma once
#include "Card.h"
#include "Player.h"

class PoisonCard : public Card {
public: 
	explicit PoisonCard(int turns, int damage);

	void play(
		Player& self,
		Player& opponent
	) override;

private:
	int turns;
	int damage;
};
