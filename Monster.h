#ifndef MONSTER_H__
#define MONSTER_H__
#include <iostream>
#include <string>
#include "Character.h"
class Monster : public Character{
    public:
    Monster(); //initalised attributes (ints and string)
    void setMonster(); //sets monsters stats
    std::string getNameMonster(); //returns name of the monster
    int damageCalculator(); //damage calculator for the monster
};
#endif //MONSTER_H_