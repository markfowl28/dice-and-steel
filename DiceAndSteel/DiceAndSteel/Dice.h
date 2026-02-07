#pragma once
#include <string>

enum class DiceFace {
    Attack,
    Defend,
    Miss,
    Critical,
    Counter,
    Wild
};

DiceFace rollDie();

std::string toString(DiceFace face);
