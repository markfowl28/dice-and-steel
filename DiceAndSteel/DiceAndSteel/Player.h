#pragma once
#include <vector>
#include <memory>
#include <utility>
#include "TurnPhase.h"
#include "StatusEffect.h"

struct Player {
    int health = 10;
    int bonusAttack = 0;
    int bonusDefense = 0;

    bool isStunned = false;

    std::vector<std::unique_ptr<StatusEffect>> statusEffects;

    bool isAlive() const {
        return health > 0;
    }

    void takeDamage(int amount) {
        health -= amount;
        if (health < 0) health = 0;
    }

    void applyStatus(std::unique_ptr<StatusEffect> effect) {
        statusEffects.push_back(std::move(effect));
    }

    void processStatusEffects(TurnPhase phase, Player& opponent);
};
