#ifndef CHARACTER_H__
#define CHARACTER_H__
#include <iostream>
#include <string>
//monster and player inherit from character.h
class Character{
    public:
    
    int damage; //the damage level of the monster or player
    int maxHealth; //the maximum health level of the monster or player
    int critChance; //the crit chance level of the monster or player
    int dexterity; //the dexterity level of the monster or player
    int level; //the level of monster or player
    int crit; //variable used to determine whether a critical hit happens
    std::string name; //the name of the monster or player
    // virtual int SelectMove(){
    //     return 0;
    // }
    
};
#endif //CHARACTER_H_