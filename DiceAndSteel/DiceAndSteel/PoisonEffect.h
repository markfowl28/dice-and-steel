#pragma once
#include "StatusEffect.h"
#include "Player.h"
#include "TurnPhase.h"

class PoisonEffect : public StatusEffect {
public:
	explicit PoisonEffect(int turns, int damage);

	void onPhase(
		TurnPhase phase,
		Player& self,
		Player& opponent
	) override;

	bool isExpired() const override;

private:
	int remainingTurns;
	int damagePerTurn;
};
