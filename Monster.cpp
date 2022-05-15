#include <iostream>
#include <math.h>
#include "Monster.h"
#include "Player.h"
using namespace std;

Monster::Monster() {
    //initalising the starting values for the attributes contained in Monster.h
    damage = 0;
    maxHealth = 0;
    critChance = 0;
    dodge = 0;
    mname = "?";
    level = 1;
}

void Monster::setMonster() {
    int a = 1+( rand() % 20 );
    switch (a) {
        case 1: mname = "Goblin";
            damage = pow(level, 1.25) + 1;
            maxHealth = pow(level, 1.25) + 1; 
            critChance = pow(level, 1.25) + 3;
            dodge = pow(level, 1.25) + 5;
        case 2: mname = "Golem";
            damage = pow(level, 1.25) + 3;
            maxHealth = pow(level, 1.25) + 5;
            critChance = pow(level, 1.25) + 3;
            dodge = pow(level, 1.25) + 1;
        case 3: mname = "Assassin";
            damage = pow(level, 1.25) + 1;
            maxHealth = pow(level, 1.25) + 1;
            critChance = pow(level, 1.25) + 3;
            dodge = pow(level, 1.25) + 5;
        case 4: mname = "Baron";
            damage = pow(level, 1.25) + 3;
            maxHealth = pow(level, 1.25) + 3;
            critChance = pow(level, 1.25) + 1;
            dodge = pow(level, 1.25) + 3;
        case 5: mname = "Knight";
            damage = pow(level, 1.25) + 4;
            maxHealth = pow(level, 1.25) + 3;
            critChance = pow(level, 1.25) + 3;
            dodge = pow(level, 1.25) + 1;
        case 6: mname = "Orc";
            damage = pow(level, 1.25) + 2;
            maxHealth = pow(level, 1.25) + 2;
            critChance = pow(level, 1.25) + 5;
            dodge = pow(level, 1.25) + 1;
        case 7: mname = "Ogre";
            damage = pow(level, 1.25) + 2;
            maxHealth = pow(level, 1.25) + 5;
            critChance = pow(level, 1.25) + 2;
            dodge = pow(level, 1.25) + 1;
        case 8: mname = "Paladin";
            damage = pow(level, 1.25) + 4;
            maxHealth = pow(level, 1.25) + 2;
            critChance = pow(level, 1.25) + 4;
            dodge = pow(level, 1.25) + 2;
        case 9: mname = "Wisp";
            damage = pow(level, 1.25) + 1;
            maxHealth = pow(level, 1.25) + 1;
            critChance = pow(level, 1.25) + 1;
            dodge = pow(level, 1.25) + 1;
        case 10: mname = "Mummy";
            damage = pow(level, 1.25) + 1;
            maxHealth = pow(level, 1.25) + 1;
            critChance = pow(level, 1.25) + 5;
            dodge = pow(level, 1.25) + 3;
        case 11: mname = "Wyvern";
            damage = pow(level, 1.25) + 2;
            maxHealth = pow(level, 1.25) + 4;
            critChance = pow(level, 1.25) + 1;
            dodge = pow(level, 1.25) + 2;
        case 12: mname = "Wizard";
            damage = pow(level, 1.25) + 3;
            maxHealth = pow(level, 1.25) + 1;
            critChance = pow(level, 1.25) + 5;
            dodge = pow(level, 1.25) + 2;
        case 13: mname = "Dragon";
            damage = pow(level, 1.25) + 5;
            maxHealth = pow(level, 1.25) + 5;
            critChance = pow(level, 1.25) + 1;
            dodge = pow(level, 1.25) + 1;
        case 14: mname = "Griffen";
            damage = pow(level, 1.25) + 1;
            maxHealth = pow(level, 1.25) + 1;
            critChance = pow(level, 1.25) + 1;
            dodge = pow(level, 1.25) + 5;
        case 15: mname = "Angel";
            damage = pow(level, 1.25) + 1;
            maxHealth = pow(level, 1.25) + 5;
            critChance = pow(level, 1.25) + 1;
            dodge = pow(level, 1.25) + 5;
        case 16: mname = "Demon";
            damage = pow(level, 1.25) + 4;
            maxHealth = pow(level, 1.25) + 1;
            critChance = pow(level, 1.25) + 4;
            dodge = pow(level, 1.25) + 1;
        case 17: mname = "Rock Elemental";
            damage = pow(level, 1.25) + 3;
            maxHealth = pow(level, 1.25) + 3;
            critChance = pow(level, 1.25) + 3;
            dodge = pow(level, 1.25) + 1;
        case 18: mname = "Leprechaun";
            damage = pow(level, 1.25) + 1;
            maxHealth = pow(level, 1.25) + 3;
            critChance = pow(level, 1.25) + 1;
            dodge = pow(level, 1.25) + 5;
        case 19: mname = "Giant";
            damage = pow(level, 1.25) + 4;
            maxHealth = pow(level, 1.25) + 5;
            critChance = pow(level, 1.25) + 3;
            dodge = pow(level, 1.25) + 1;
        case 20: mname = "Jeff's Mum";
            damage = pow(level, 1.25);
            maxHealth = pow(level, 1.25) + 5;
            critChance = pow(level, 1.25);
            dodge = pow(level, 1.25) + 1;
    }
}

std::string Monster::getNameMonster() {
    //returns monsters name
    return mname;
}

int Monster::damageCalculator() {
    return 0;
}