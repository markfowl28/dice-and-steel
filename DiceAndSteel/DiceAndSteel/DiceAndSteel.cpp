// Dice & Steel - Core Dice System
// Handles random dice rolls and face mapping

#include <iostream>
#include <random>
#include <string>

enum class DiceFace {
    Attack,
    Defend,
    Miss,
    Critical,
    Counter,
    Wild
};

// Rolls a six-sided die using a high-quality RNG.
// Static engine prevents reseeding on each roll.
DiceFace rollDie() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<int> dist(1, 6);

    int roll = dist(gen);

    switch (roll) {
    case 1: return DiceFace::Attack;
    case 2: return DiceFace::Defend;
    case 3: return DiceFace::Miss;
    case 4: return DiceFace::Critical;
    case 5: return DiceFace::Counter;
    case 6: return DiceFace::Wild;
    default: return DiceFace::Miss;
    }
}

std::string toString(DiceFace face) {
    switch (face) {
    case DiceFace::Attack: return "Attack";
    case DiceFace::Defend: return "Defend";
    case DiceFace::Miss: return "Miss";
    case DiceFace::Critical: return "Critical";
    case DiceFace::Counter: return "Counter";
    case DiceFace::Wild: return "Wild";
    default: return "Unknown";
    }
}

enum class Role {
    Attacker,
    Defender
};

enum class CombatIntent {
    Attack,
    Defend,
    Counter,
    None
};

CombatIntent mapDiceToIntent(DiceFace face, Role role) {
    if (role == Role::Attacker) {
        switch (face) {
        case DiceFace::Attack:
        case DiceFace::Critical:
            return CombatIntent::Attack;
        default: return CombatIntent::None;
        }
    }

    if (role == Role::Defender) {
        switch (face) {
        case DiceFace::Defend: 
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

int main()
{
    std::cout << "Dice & Steel starting up...\n";
    std::cout << "Rolling dice....\n";

    Role role = Role::Defender;

    for (int i = 0; i < 5; i++) {
        DiceFace roll = rollDie();
        CombatIntent intent = mapDiceToIntent(roll, role);

        std::cout << "Rolled: " << toString(roll)
            << " -> Intent: " << toString(intent)
            << " (" << toString(role) << ")\n";
    }
}
