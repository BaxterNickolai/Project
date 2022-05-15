#include <iostream>
#include <math.h>
#include "Monster.h"
#include "Player.h"
using namespace std;

Monster::Monster() {
    //initalising the starting values for the attributes contained in Monster.h
    mdamage = 0;
    maxHealth = 0;
    mcritChance = 0;
    mdodge = 0;
    mname = "?";
    level = 1;
}

void Monster::setMonster() {
    int a = 1+( rand() % 20 );
    switch (a) {
        case 1: mname = "Goblin";
            mdamage = pow(level, 1.25) + 1;
            maxHealth = pow(level, 1.25) + 1; 
            mcritChance = pow(level, 1.25) + 3;
            mdodge = pow(level, 1.25) + 5;
        case 2: mname = "Golem";
            mdamage = pow(level, 1.25) + 3;
            maxHealth = pow(level, 1.25) + 5;
            mcritChance = pow(level, 1.25) + 3;
            mdodge = pow(level, 1.25) + 1;
        case 3: mname = "Assassin";
            mdamage = pow(level, 1.25) + 1;
            maxHealth = pow(level, 1.25) + 1;
            mcritChance = pow(level, 1.25) + 3;
            mdodge = pow(level, 1.25) + 5;
        case 4: mname = "Baron";
            mdamage = pow(level, 1.25) + 3;
            maxHealth = pow(level, 1.25) + 3;
            mcritChance = pow(level, 1.25) + 1;
            mdodge = pow(level, 1.25) + 3;
        case 5: mname = "Knight";
            mdamage = pow(level, 1.25) + 4;
            maxHealth = pow(level, 1.25) + 3;
            mcritChance = pow(level, 1.25) + 3;
            mdodge = pow(level, 1.25) + 1;
        case 6: mname = "Orc";
            mdamage = pow(level, 1.25) + 2;
            maxHealth = pow(level, 1.25) + 2;
            mcritChance = pow(level, 1.25) + 5;
            mdodge = pow(level, 1.25) + 1;
        case 7: mname = "Ogre";
            mdamage = pow(level, 1.25) + 2;
            maxHealth = pow(level, 1.25) + 5;
            mcritChance = pow(level, 1.25) + 2;
            mdodge = pow(level, 1.25) + 1;
        case 8: mname = "Paladin";
            mdamage = pow(level, 1.25) + 4;
            maxHealth = pow(level, 1.25) + 2;
            mcritChance = pow(level, 1.25) + 4;
            mdodge = pow(level, 1.25) + 2;
        case 9: mname = "Wisp";
            mdamage = pow(level, 1.25) + 1;
            maxHealth = pow(level, 1.25) + 1;
            mcritChance = pow(level, 1.25) + 1;
            mdodge = pow(level, 1.25) + 1;
        case 10: mname = "Mummy";
            mdamage = pow(level, 1.25) + 1;
            maxHealth = pow(level, 1.25) + 1;
            mcritChance = pow(level, 1.25) + 5;
            mdodge = pow(level, 1.25) + 3;
        case 11: mname = "Wyvern";
            mdamage = pow(level, 1.25) + 2;
            maxHealth = pow(level, 1.25) + 4;
            mcritChance = pow(level, 1.25) + 1;
            mdodge = pow(level, 1.25) + 2;
        case 12: mname = "Wizard";
            mdamage = pow(level, 1.25) + 3;
            maxHealth = pow(level, 1.25) + 1;
            mcritChance = pow(level, 1.25) + 5;
            mdodge = pow(level, 1.25) + 2;
        case 13: mname = "Dragon";
            mdamage = pow(level, 1.25) + 5;
            maxHealth = pow(level, 1.25) + 5;
            mcritChance = pow(level, 1.25) + 1;
            mdodge = pow(level, 1.25) + 1;
        case 14: mname = "Griffen";
            mdamage = pow(level, 1.25) + 1;
            maxHealth = pow(level, 1.25) + 1;
            mcritChance = pow(level, 1.25) + 1;
            mdodge = pow(level, 1.25) + 5;
        case 15: mname = "Angel";
            mdamage = pow(level, 1.25) + 1;
            maxHealth = pow(level, 1.25) + 5;
            mcritChance = pow(level, 1.25) + 1;
            mdodge = pow(level, 1.25) + 5;
        case 16: mname = "Demon";
            mdamage = pow(level, 1.25) + 4;
            maxHealth = pow(level, 1.25) + 1;
            mcritChance = pow(level, 1.25) + 4;
            mdodge = pow(level, 1.25) + 1;
        case 17: mname = "Rock Elemental";
            mdamage = pow(level, 1.25) + 3;
            maxHealth = pow(level, 1.25) + 3;
            mcritChance = pow(level, 1.25) + 3;
            mdodge = pow(level, 1.25) + 1;
        case 18: mname = "Leprechaun";
            mdamage = pow(level, 1.25) + 1;
            maxHealth = pow(level, 1.25) + 3;
            mcritChance = pow(level, 1.25) + 1;
            mdodge = pow(level, 1.25) + 5;
        case 19: mname = "Giant";
            mdamage = pow(level, 1.25) + 4;
            maxHealth = pow(level, 1.25) + 5;
            mcritChance = pow(level, 1.25) + 3;
            mdodge = pow(level, 1.25) + 1;
        case 20: mname = "Jeff's Mum";
            mdamage = pow(level, 1.25);
            maxHealth = pow(level, 1.25) + 5;
            mcritChance = pow(level, 1.25);
            mdodge = pow(level, 1.25) + 1;
    }
}

std::string Monster::getNameMonster() {
    //returns monsters name
    return mname;
}

int Monster::mDamageCalculator() {
    return 0;
}