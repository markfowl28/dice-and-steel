#pragma once
#include "StatusEffect.h"
#include "TurnPhase.h"
#include "Player.h"

class BuffAttackEffect : public StatusEffect {
public:
	explicit BuffAttackEffect(int turns = 1);

	void onPhase(
		TurnPhase phase,
		Player& self,
		Player& opponent
	) override;

	bool isExpired() const override;

private:
	int remainingTurns;
};
