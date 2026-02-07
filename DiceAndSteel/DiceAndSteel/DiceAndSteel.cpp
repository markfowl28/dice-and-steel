#include <iostream>
#include "Dice.h"
#include "Combat.h"

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
