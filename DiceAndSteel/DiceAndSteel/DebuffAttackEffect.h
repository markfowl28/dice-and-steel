#pragma once
#include "StatusEffect.h"
#include "TurnPhase.h"
#include "Player.h"

class DebuffAttackEffect : public StatusEffect {
public:
	explicit DebuffAttackEffect(int turns);

	void onPhase(
		TurnPhase phase,
		Player& self,
		Player& opponent
	) override;

	bool isExpired() const override;

private:
	int remainingTurns;
};
