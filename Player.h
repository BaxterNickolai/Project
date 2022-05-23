#ifndef PLAYER_H__
#define PLAYER_H__
#include <iostream>
#include <string>
#include "Character.h"
class Player : public Character {
    public:
    
    Player(); //initalised attributes (ints and string)
    void setName(std::string playerName); //sets the name of the player
    int selectStat(); //allows the player to select a stat to upgrade 
    std::string getName(); //returns the name of the player
    void setStats(); //sets the stats of the player based on what the user wants to input into each stat
    int InputValidator(int, int); //validates user input is within range given
    void selectNum(int); //selects damage, health, dexterity, or crit to increase for player when leveled up
    
    int points; //how many points are available for the player to increase their stats level (damage, maxHealth, critCahnce and dexterity)
    int xp; //the xp of the character (contributes to the level)
    
};
#endif //PLAYER_H_