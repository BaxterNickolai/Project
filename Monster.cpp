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
    dexterity = 0;
    name = "?";
}

void Monster::setMonster() {
    //sets a new random value for the random function
    srand(time(NULL));
    //produces a random number between 1 and 20
    int a = 1+( rand() % 20 );
    //dependent on the random number a pre-set monster is generated
    switch (a) {
        case 1: name = "Goblin";
            damage = pow(level, 1.25) + 1;
            maxHealth = pow(level, 1.25) + 5;
            critChance = pow(level, 1.25) + 3;
            dexterity = pow(level, 1.25) + 5;
        break;
        case 2: name = "Golem";
            damage = pow(level, 1.25) + 3;
            maxHealth = pow(level, 1.25) + 20;
            critChance = pow(level, 1.25) + 3;
            dexterity = pow(level, 1.25) + 1;
        break;
        case 3: name = "Assassin";
            damage = pow(level, 1.25) + 1;
            maxHealth = pow(level, 1.25) + 6;
            critChance = pow(level, 1.25) + 3;
            dexterity = pow(level, 1.25) + 5;
        break;
        case 4: name = "Baron";
            damage = pow(level, 1.25) + 3;
            maxHealth = pow(level, 1.25) + 30;
            critChance = pow(level, 1.25) + 1;
            dexterity = pow(level, 1.25) + 3;
        break;
        case 5: name = "Knight";
            damage = pow(level, 1.25) + 4;
            maxHealth = pow(level, 1.25) + 30;
            critChance = pow(level, 1.25) + 3;
            dexterity = pow(level, 1.25) + 1;
        break;
        case 6: name = "Orc";
            damage = pow(level, 1.25) + 2;
            maxHealth = pow(level, 1.25) + 20;
            critChance = pow(level, 1.25) + 5;
            dexterity = pow(level, 1.25) + 1;
        break;
        case 7: name = "Ogre";
            damage = pow(level, 1.25) + 2;
            maxHealth = pow(level, 1.25) + 50;
            critChance = pow(level, 1.25) + 2;
            dexterity = pow(level, 1.25) + 1;
        break;
        case 8: name = "Paladin";
            damage = pow(level, 1.25) + 4;
            maxHealth = pow(level, 1.25) + 20;
            critChance = pow(level, 1.25) + 4;
            dexterity = pow(level, 1.25) + 2;
        break;
        case 9: name = "Wisp";
            damage = pow(level, 1.25) + 1;
            maxHealth = pow(level, 1.25) + 1;
            critChance = pow(level, 1.25) + 1;
            dexterity = pow(level, 1.25) + 1;
        break;
        case 10: name = "Mummy";
            damage = pow(level, 1.25) + 1;
            maxHealth = pow(level, 1.25) + 15;
            critChance = pow(level, 1.25) + 5;
            dexterity = pow(level, 1.25) + 3;
        break;
        case 11: name = "Wyvern";
            damage = pow(level, 1.25) + 2;
            maxHealth = pow(level, 1.25) + 40;
            critChance = pow(level, 1.25) + 1;
            dexterity = pow(level, 1.25) + 2;
        break;
        case 12: name = "Wizard";
            damage = pow(level, 1.25) + 3;
            maxHealth = pow(level, 1.25) + 10;
            critChance = pow(level, 1.25) + 5;
            dexterity = pow(level, 1.25) + 2;
        break;
        case 13: name = "Dragon";
            damage = pow(level, 1.25) + 5;
            maxHealth = pow(level, 1.25) + 50;
            critChance = pow(level, 1.25) + 1;
            dexterity = pow(level, 1.25) + 1;
        break;
        case 14: name = "Griffen";
            damage = pow(level, 1.25) + 1;
            maxHealth = pow(level, 1.25) + 10;
            critChance = pow(level, 1.25) + 1;
            dexterity = pow(level, 1.25) + 5;
        break;
        case 15: name = "Angel";
            damage = pow(level, 1.25) + 1;
            maxHealth = pow(level, 1.25) + 50;
            critChance = pow(level, 1.25) + 1;
            dexterity = pow(level, 1.25) + 5;
        break;
        case 16: name = "Demon";
            damage = pow(level, 1.25) + 4;
            maxHealth = pow(level, 1.25) + 10;
            critChance = pow(level, 1.25) + 4;
            dexterity = pow(level, 1.25) + 1;
        break;
        case 17: name = "Rock Elemental";
            damage = pow(level, 1.25) + 3;
            maxHealth = pow(level, 1.25) + 30;
            critChance = pow(level, 1.25) + 3;
            dexterity = pow(level, 1.25) + 1;
        break;
        case 18: name = "Leprechaun";
            damage = pow(level, 1.25) + 1;
            maxHealth = pow(level, 1.25) + 20;
            critChance = pow(level, 1.25) + 1;
            dexterity = pow(level, 1.25) + 5;
        break;
        case 19: name = "Giant";
            damage = pow(level, 1.25) + 4;
            maxHealth = pow(level, 1.25) + 50;
            critChance = pow(level, 1.25) + 3;
            dexterity = pow(level, 1.25) + 1;
        break;
        case 20: name = "Jeff's Mum";
            damage = pow(level, 1.25);
            maxHealth = pow(level, 1.25) + 50;
            critChance = pow(level, 1.25);
            dexterity = pow(level, 1.25);
        break;
    }
}