#ifndef GAMESTATS_H__
#define GAMESTATS_H__
#include <iostream>
class GameStats{
    public:
    GameStats();
    int monstersKilled;
    int level;
    int playerCrits;
    int damageDealt;;
    void printStats();
}; 
#endif //GAMESTATS_H_