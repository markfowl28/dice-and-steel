#pragma once
#include "TurnSnapshot.h"
#include "Player.h"

class GameEngine {
public:
	GameEngine();

	void runGame();

private:
	Player attacker;
	Player defender;
};

TurnSnapshot buildTurn(Player& attacker, Player& defender);

