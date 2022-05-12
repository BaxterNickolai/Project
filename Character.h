#ifndef CHARACTER_H__
#define CHARACTER_H__
#include <iostream>
#include <string>
class Character{
    public:
    int cDamageCalculator();
    
    int damage;
    int maxHealth;
    int critChance;
    int dodge;
    std::string name;
}