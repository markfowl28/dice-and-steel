#pragma once
#include "StatusEffect.h"
#include "Player.h"
#include "TurnPhase.h"

class BuffDefenseEffect : public StatusEffect {
public:
	explicit BuffDefenseEffect(int turns);

	void onPhase(
		TurnPhase phase,
		Player& self,
		Player& opponent
	) override;

	bool isExpired() const override;

private:
	int remainingTurns;
};
