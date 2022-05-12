#ifndef PLAYER_H__
#define PLAYER_H__
#include <iostream>
#include <string>
class Player{
    public:
    
    int damage;
    int maxHealth;
    int critChance;
    int dodge;
    int xp;
    int level;
    std::string name;
}