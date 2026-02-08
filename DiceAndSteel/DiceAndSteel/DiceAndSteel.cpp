#include <iostream>
#include "Dice.h"
#include "Combat.h"
#include "Resolution.h"

int main()
{
    std::cout << "Dice & Steel starting up...\n";
    std::cout << "Rolling dice....\n\n";

    for (int i = 0; i < 5; i++) {
        DiceFace roll = rollDie();

        CombatIntent attackerIntent = mapDiceToIntent(roll, Role::Attacker);
        CombatIntent defenderIntent = mapDiceToIntent(roll, Role::Defender);

        ResolutionResult result = resolveCombat(attackerIntent, defenderIntent);

        std::cout << "Roll: " << toString(roll) << "\n";
        std::cout << "Attacker Intent: " << toString(attackerIntent) << "\n";
        std::cout << "Defender Intent: " << toString(defenderIntent) << "\n";
        std::cout << "Damage -> Defender: " << result.damageToDefender
                  << " | Attacker: " << result.damageToAttacker << "\n\n";
    }
}
