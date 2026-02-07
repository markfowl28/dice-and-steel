#include "Dice.h"
#include <random>
#include <string>

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