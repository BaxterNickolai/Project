#ifndef MONSTER_H__
#define MONSTER_H__
#include <iostream>
#include <string>
#include "Character.h"
class Monster : public Character{
    public:
    Monster(); //initalised attributes (ints and string)
    void setMonster(); //sets monsters stats
};
#endif //MONSTER_H_