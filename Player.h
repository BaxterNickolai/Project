#ifndef PLAYER_H__
#define PLAYER_H__
#include <iostream>
#include <string>
class Player{
    public:
    Player(); //initalised attributes (ints and string)
    void setName(std::string playerName); //sets the name of the player
    std::string getName(); //returns the name of the player
    void setStats(); //sets the stats of the player based on what the user wants to input into each stat
    int damage; //damage level of player
    int maxHealth; //maximum health level of player
    int critChance; //critical chance level of player
    int dodge; //dodge level of player
    int points; //how many points are available for the player to increase their stats level (damage, maxHealth, critCahnce and dodge)
    int xp; //the xp of the character (contributes to the level)
    int level; //the level the character is on, which increases based on xp, affected by combat and affects stats level
    std::string name; //the name of player
};
#endif //PLAYER_H_