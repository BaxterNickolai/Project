#ifndef MONSTER_H__
#define MONSTER_H__
#include <iostream>
#include <string>
class Monster{
    public:
    Monster(); //initalised attributes (ints and string)
    void setMonster(); //sets monsters stats
    std::string getNameMonster(); //returns name of the monster
    int damageCalculator(); //damage calculator for the monster
    
    int damage; //damage of the monster
    int maxHealth; //maxmimum health of the monster
    int critChance; //critical chance of the monster
    int dodge; //dodge chance of the monster
    int level; //level of the monster
    std::string name; //name of the monster
};
#endif //MONSTER_H_