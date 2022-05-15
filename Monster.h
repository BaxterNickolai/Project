#ifndef MONSTER_H__
#define MONSTER_H__
#include <iostream>
#include <string>
class Monster{
    public:
    monster(); //initalised attributes (ints and string)
    void setNameMonster(); //sets the name of the monster
    std::string getNameMonster(); //returns name of the monster
    int mDamageCalculator(); //damage calculator for the monster
    
    int mdamage; //damage of the monster
    int mmaxHealth; //maxmimum health of the monster
    int mcritChance; //critical chance of the monster
    int mdodge; //dodge chance of the monster
    std::string mname; //name of the monster
}