#include "TurnPhase.h"
#include "Player.h"
#include <algorithm>
#include <memory>
#include "StatusEffect.h"

void Player::processStatusEffects(TurnPhase phase, Player& opponent) {
    for (auto& effect : statusEffects) {
        effect->onPhase(phase, *this, opponent);
    }

    statusEffects.erase(
        std::remove_if(
            statusEffects.begin(),
            statusEffects.end(),
            [](const std::unique_ptr<StatusEffect>& e) {
                return e->isExpired();
            }
        ),
        statusEffects.end()
    );
}