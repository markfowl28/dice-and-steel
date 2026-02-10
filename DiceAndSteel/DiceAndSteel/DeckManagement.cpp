#include <memory>
#include <algorithm>
#include <random>
#include <vector>
#include <utility>
#include "DeckManager.h"
#include "Card.h"
#include "Player.h"

void DeckManager::shuffleDrawPile() {
	std::random_device rd;
	std::mt19937 g(rd());

	std::vector<std::unique_ptr<Card>> temp;
	while (!drawPile.empty()) {
		temp.push_back(std::move(drawPile.front()));
		drawPile.pop_front();
	}

	std::shuffle(temp.begin(), temp.end(), g);

	for (auto& card : temp) {
		drawPile.push_back(std::move(card));
	}
}

void DeckManager::drawHand() {
	hand.clear();
	for (int i = 0; i < handSize && !drawPile.empty(); i++) {
		hand.push_back(std::move(drawPile.front()));
		drawPile.pop_front();
	}
}

void DeckManager::playCard(int handIndex, Player& self, Player& opponent) {
	if (handIndex < 0 || handIndex >= (int)hand.size()) return;

	hand[handIndex]->play(self, opponent);
	discardPile.push_back(std::move(hand[handIndex]));
	hand.erase(hand.begin() + handIndex);
}

void DeckManager::reshuffleDiscardPileIntoHand() {
	for (auto& card : discardPile) {
		drawPile.push_back(std::move(card));
	}
	discardPile.clear();
	shuffleDrawPile();
}

