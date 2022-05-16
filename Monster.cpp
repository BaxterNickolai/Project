#include <iostream>
#include <math.h> 
#include <time.h>
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
    srand(time(NULL));
    int a = 1+( rand() % 20 );
    std::cout<<"random number is "<<a; 
    switch (a) { 
        case 1: mname = "Goblin";
            damage = pow(level, 1.25) + 1;
            maxHealth = pow(level, 1.25) + 1; 
            critChance = pow(level, 1.25) + 3;
            dodge = pow(level, 1.25) + 5;
        break; 
        case 2: mname = "Golem";
            damage = pow(level, 1.25) + 3;
            maxHealth = pow(level, 1.25) + 5;
            critChance = pow(level, 1.25) + 3;
            dodge = pow(level, 1.25) + 1;
        break;
        case 3: mname = "Assassin";
            damage = pow(level, 1.25) + 1;
            maxHealth = pow(level, 1.25) + 1;
            critChance = pow(level, 1.25) + 3;
            dodge = pow(level, 1.25) + 5;
        break;
        case 4: mname = "Baron";
            damage = pow(level, 1.25) + 3;
            maxHealth = pow(level, 1.25) + 3;
            critChance = pow(level, 1.25) + 1;
            dodge = pow(level, 1.25) + 3;
        break;
        case 5: mname = "Knight";
            damage = pow(level, 1.25) + 4;
            maxHealth = pow(level, 1.25) + 3;
            critChance = pow(level, 1.25) + 3;
            dodge = pow(level, 1.25) + 1;
        break;
        case 6: mname = "Orc";
            damage = pow(level, 1.25) + 2;
            maxHealth = pow(level, 1.25) + 2;
            critChance = pow(level, 1.25) + 5;
            dodge = pow(level, 1.25) + 1;
        break;
        case 7: mname = "Ogre";
            damage = pow(level, 1.25) + 2;
            maxHealth = pow(level, 1.25) + 5;
            critChance = pow(level, 1.25) + 2;
            dodge = pow(level, 1.25) + 1;
        break;
        case 8: mname = "Paladin";
            damage = pow(level, 1.25) + 4;
            maxHealth = pow(level, 1.25) + 2;
            critChance = pow(level, 1.25) + 4;
            dodge = pow(level, 1.25) + 2;
        break;
        case 9: mname = "Wisp";
            damage = pow(level, 1.25) + 1;
            maxHealth = pow(level, 1.25) + 1;
            critChance = pow(level, 1.25) + 1;
            dodge = pow(level, 1.25) + 1;
        break;
        case 10: mname = "Mummy";
            damage = pow(level, 1.25) + 1;
            maxHealth = pow(level, 1.25) + 1;
            critChance = pow(level, 1.25) + 5;
            dodge = pow(level, 1.25) + 3;
        break;
        case 11: mname = "Wyvern";
            damage = pow(level, 1.25) + 2;
            maxHealth = pow(level, 1.25) + 4;
            critChance = pow(level, 1.25) + 1;
            dodge = pow(level, 1.25) + 2;
        break;
        case 12: mname = "Wizard";
            damage = pow(level, 1.25) + 3;
            maxHealth = pow(level, 1.25) + 1;
            critChance = pow(level, 1.25) + 5;
            dodge = pow(level, 1.25) + 2;
        break;
        case 13: mname = "Dragon";
            damage = pow(level, 1.25) + 5;
            maxHealth = pow(level, 1.25) + 5;
            critChance = pow(level, 1.25) + 1;
            dodge = pow(level, 1.25) + 1;
        break;
        case 14: mname = "Griffen";
            damage = pow(level, 1.25) + 1;
            maxHealth = pow(level, 1.25) + 1;
            critChance = pow(level, 1.25) + 1;
            dodge = pow(level, 1.25) + 5;
        break;
        case 15: mname = "Angel";
            damage = pow(level, 1.25) + 1;
            maxHealth = pow(level, 1.25) + 5;
            critChance = pow(level, 1.25) + 1;
            dodge = pow(level, 1.25) + 5;
        break;
        case 16: mname = "Demon";
            damage = pow(level, 1.25) + 4;
            maxHealth = pow(level, 1.25) + 1;
            critChance = pow(level, 1.25) + 4;
            dodge = pow(level, 1.25) + 1;
        break;
        case 17: mname = "Rock Elemental";
            damage = pow(level, 1.25) + 3;
            maxHealth = pow(level, 1.25) + 3;
            critChance = pow(level, 1.25) + 3;
            dodge = pow(level, 1.25) + 1;
        break;
        case 18: mname = "Leprechaun";
            damage = pow(level, 1.25) + 1;
            maxHealth = pow(level, 1.25) + 3;
            critChance = pow(level, 1.25) + 1;
            dodge = pow(level, 1.25) + 5;
        break;
        case 19: mname = "Giant";
            damage = pow(level, 1.25) + 4;
            maxHealth = pow(level, 1.25) + 5;
            critChance = pow(level, 1.25) + 3;
            dodge = pow(level, 1.25) + 1;
        break;
        case 20: mname = "Jeff's Mum";
            damage = pow(level, 1.25);
            maxHealth = pow(level, 1.25) + 5;
            critChance = pow(level, 1.25);
            dodge = pow(level, 1.25);
        break;
    }
}

int Monster::damageCalculator() {
    return 0;
}