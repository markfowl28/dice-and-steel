#pragma once
#include <deque>
#include <memory>
#include <vector>
#include <utility>
#include "Card.h"
#include "Player.h"

class DeckManager {
public:
	DeckManager(int handSize = 3) : handSize(handSize) {}

	void addToDraw(std::unique_ptr<Card> card) {
		drawPile.push_back(std::move(card));
	}

	void shuffleDrawPile();
	
	void drawHand();

	void playCard(
		int handIndex, Player& self, Player& opponent 
	);

	void reshuffleDiscardPileIntoHand();

private:
	std::deque<std::unique_ptr<Card>> drawPile;
	std::vector<std::unique_ptr<Card>> hand;
	std::vector<std::unique_ptr<Card>> discardPile;
	int handSize;
};
