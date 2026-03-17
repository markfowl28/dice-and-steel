#include "Combat.h"
#include <string>
#include "Dice.h"

CombatIntent mapDiceToIntent(DiceFace face, Role role) {
    if (role == Role::Attacker) {
        switch (face) {
        case DiceFace::Critical:
            return CombatIntent::Critical;
        case DiceFace::Attack:
        case DiceFace::Wild:
            return CombatIntent::Attack;
        default: return CombatIntent::None;
        }
    }

    if (role == Role::Defender) {
        switch (face) {
        case DiceFace::Defend:
        case DiceFace::Wild:
            return CombatIntent::Defend;
        case DiceFace::Counter:
            return CombatIntent::Counter;
        default: return CombatIntent::None;
        }
    }

    return CombatIntent::None;
}

std::string toString(Role role) {
    return role == Role::Attacker ? "Attacker" : "Defender";
}

std::string toString(CombatIntent intent) {
    switch (intent) {
    case CombatIntent::Attack: return "Attack";
    case CombatIntent::Defend: return "Defend";
    case CombatIntent::Counter: return "Counter";
    case CombatIntent::None: return "None";
    default: return "None";
    }
}

