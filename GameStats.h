#ifndef GAMESTATS_H__
#define GAMESTATS_H__
#include <iostream>
class GameStats{
    public:
    
    GameStats(); //initalises the gamestats values
    void printStats(); //prints the gamestats for the player
    
    int monstersKilled; // the number of monsters killed
    int level; // the level of the player
    int playerCrits; //the number of crits dealt
    int damageDealt; //the amount of damage dealt
    
}; 
#endif //GAMESTATS_H_