#pragma once
#include "Player.h"
#include <string>

class Card {
public:
	virtual ~Card() = default;

	virtual void play(
		Player& self,
		Player& opponent
	) = 0;

	virtual std::string name() const = 0;
	virtual std::string description() const = 0;
};
