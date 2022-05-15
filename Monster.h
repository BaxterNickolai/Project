#ifndef MONSTER_H__
#define MONSTER_H__
#include <iostream>
#include <string>
class Monster{
    public:
    monster(); //initalised attributes (ints and string)
    void setNameMonster(std::string monsterName); //sets the name of the player
    std::string getNameMonster(); //returns name of the monster
    int mDamageCalculator(); //damage calculator for the monster
    
    int damage; //damage of the monster
    int maxHealth; //maxmimum health of the monster
    int critChance; //critical chance of the monster
    int dodge; //dodge chance of the monster
    std::string name; //name of the monster
}