#pragma once
#include "TurnPhase.h"

struct Player;

struct StatusEffect {
    virtual ~StatusEffect() = default;

    virtual void onPhase(
        TurnPhase phase,
        Player& self,
        Player& opponent
    ) = 0;

    virtual bool isExpired() const = 0;
};
