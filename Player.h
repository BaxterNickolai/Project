#ifndef PLAYER_H__
#define PLAYER_H__
#include <iostream>
#include <string>
class Player{
    public:
    player();
    void setName(std::string playerName);
    std::string getName();
    void setStats();
    
    int damage;
    int maxHealth;
    int critChance;
    int dodge;
    int points;
    int xp;
    int level;
    std::string name;
}