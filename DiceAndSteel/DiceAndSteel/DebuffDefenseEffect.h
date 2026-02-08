#pragma once
#include "StatusEffect.h"
#include "Player.h"
#include "TurnPhase.h"

class DebuffDefenseEffect : public StatusEffect {
public:
	explicit DebuffDefenseEffect(int turns);

	void onPhase(
		TurnPhase phase,
		Player& self,
		Player& opponent
	) override;

	bool isExpired() const override;

private:
	int remainingTurns;
};
