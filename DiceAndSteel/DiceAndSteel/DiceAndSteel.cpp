#include <iostream>
#include "GameEngine.h"

int main()
{
    std::cout << "Dice & Steel starting up...\n\n";
    
    GameEngine engine;

    for (int i = 0; i < 5; i++) {
        engine.runTurn();
    }
}
