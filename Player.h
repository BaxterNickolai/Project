#ifndef PLAYER_H__
#define PLAYER_H__
#include <iostream>
#include <string>
#include "Character.h"
class Player : public Character{
    public:
    Player(); //initalised attributes (ints and string)
    void setName(std::string playerName); //sets the name of the player
    int selectStat(); //allows the player to select a stat to upgrade 
    std::string getName(); //returns the name of the player
    void setStats(); //sets the stats of the player based on what the user wants to input into each stat
    int points; //how many points are available for the player to increase their stats level (damage, maxHealth, critCahnce and dexterity)
    int xp; //the xp of the character (contributes to the level)
    int InputValidator(int, int); //validates user input
    void selectNum(int); 
};
#endif //PLAYER_H_