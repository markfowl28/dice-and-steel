#pragma once
#include "Player.h"

class Card {
public:
	virtual ~Card() = default;

	virtual void play(
		Player& self,
		Player& opponent
	) = 0;
};
