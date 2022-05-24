#include <iostream>
#include "GameStats.h"
int main(){
    {
    GameStats gamestats;
    gamestats.printStats();
    }
    {
    GameStats gamestats;
    gamestats.level = 5;
    gamestats.monstersKilled = 4;
    gamestats.damageDealt = 25;
    gamestats.playerCrits = 2;
    gamestats.printStats();
    }
    
    
    
    
    
    
    
    return 0;
}