#ifndef MONSTER_H__
#define MONSTER_H__
#include <iostream>
#include <string>
class Monster{
    public:
    Monster(); //initalised attributes (ints and string)
    void setMonster(); //sets monsters stats
    std::string getNameMonster(); //returns name of the monster
    int mDamageCalculator(); //damage calculator for the monster
    
    int mdamage; //damage of the monster
    int maxHealth; //maxmimum health of the monster
    int mcritChance; //critical chance of the monster
    int mdodge; //dodge chance of the monster
    int level; //level of the monster
    std::string mname; //name of the monster
};
#endif //MONSTER_H_