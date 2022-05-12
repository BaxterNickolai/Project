#ifndef MONSTER_H__
#define MONSTER_H__
#include <iostream>
#include <string>
class Monster{
    public:
    int mDamageCalculator();
    
    int damage;
    int maxHealth;
    int critChance;
    int dodge;
    std::string name;
}