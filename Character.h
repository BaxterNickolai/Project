#ifndef CHARACTER_H__
#define CHARACTER_H__
#include <iostream>
#include <string>
class Character{
    public:
    //monster and player inherit from character.h
    int damage; //the damage level of the monster or player
    int maxHealth; //the maximum health level of the monster or player
    int critChance; //the crit chance level of the monster or player
    int dexterity; //the dexterity level of the monster or player
    int level //the level of monster or player
    std::string name; //the name of the monster or player
};
#endif //CHARACTER_H_