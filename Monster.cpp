#include <iostream>
#include "Monster.h"
#include "Player.h"
using namespace std;

Monster::monster() {
    //initalising the starting values for the attributes contained in Monster.h
    mdamage = 0;
    mmaxHealth = 0;
    mcritChance = 0;
    mdodge = 0;
    mname = "?";
}

void Monster::setMonster() {
    int a = rand(1,20);
    switch (a) {
        case 1: mname = "Goblin"
            mdamage = level^1.25 + 1;
            mmaxHealth = level^1.25 + 1;
            mcritCahnce = level^1.25 + 3;
            mdodge = level^1.25 + 5;
        case 2: mname = "Golem"
            mdamage = level^1.25 + 3;
            mmaxHealth = level^1.25 + 5;
            mcritCahnce = level^1.25 + 3;
            mdodge = level^1.25 + 1;
        case 3: mname = "Assassin"
            mdamage = level^1.25 + 1;
            mmaxHealth = level^1.25 + 1;
            mcritCahnce = level^1.25 + 3;
            mdodge = level^1.25 + 5;
        case 4: mname = "Baron"
            mdamage = level^1.25 + 3;
            mmaxHealth = level^1.25 + 3;
            mcritCahnce = level^1.25  1;
            mdodge = level^1.25 + 3;
        case 5: mname = "Knight"
            mdamage = level^1.25 + 4;
            mmaxHealth = level^1.25 + 3;
            mcritCahnce = level^1.25 + 3;
            mdodge = level^1.25 + 1;
        case 6: mname = "Orc"
            mdamage = level^1.25 + 2;
            mmaxHealth = level^1.25 + 2;
            mcritCahnce = level^1.25 + 5;
            mdodge = level^1.25 + 1;
        case 7: mname = "Ogre"
            mdamage = level^1.25 + 2;
            mmaxHealth = level^1.25 + 5;
            mcritCahnce = level^1.25 + 2;
            mdodge = level^1.25 + 1;
        case 8: mname = "Paladin"
            mdamage = level^1.25 + 4;
            mmaxHealth = level^1.25 + 2;
            mcritCahnce = level^1.25 + 4;
            mdodge = level^1.25 + 2;
        case 9: mname = "Wisp"
            mdamage = level^1.25 + 1;
            mmaxHealth = level^1.25 + 1;
            mcritCahnce = level^1.25 + 1;
            mdodge = level^1.25 + 1;
        case 10: mname = "Mummy"
            mdamage = level^1.25 + 1;
            mmaxHealth = level^1.25 + 1;
            mcritCahnce = level^1.25 + 5;
            mdodge = level^1.25 + 3;
        case 11: mname = "Wyvern"
            mdamage = level^1.25 + 2;
            mmaxHealth = level^1.25 + 4;
            mcritCahnce = level^1.25 + 1;
            mdodge = level^1.25 + 2;
        case 12: mname = "Wizard"
            mdamage = level^1.25 + 3;
            mmaxHealth = level^1.25 + 1;
            mcritCahnce = level^1.25 + 5;
            mdodge = level^1.25 + 2;
        case 13: mname = "Dragon"
            mdamage = level^1.25 + 5;
            mmaxHealth = level^1.25 + 5;
            mcritCahnce = level^1.25 + 1;
            mdodge = level^1.25 + 1;
        case 14: mname = "Griffen"
            mdamage = level^1.25 + 1;
            mmaxHealth = level^1.25 + 1;
            mcritCahnce = level^1.25 + 1;
            mdodge = level^1.25 + 5;
        case 15: mname = "Angel"
            mdamage = level^1.25 + 1;
            mmaxHealth = level^1.25 + 5;
            mcritCahnce = level^1.25 + 1;
            mdodge = level^1.25 + 5;
        case 16: mname = "Demon"
            mdamage = level^1.25 + 4;
            mmaxHealth = level^1.25 + 1;
            mcritCahnce = level^1.25 + 4;
            mdodge = level^1.25 + 1;
        case 17: mname = "Rock Elemental"
            mdamage = level^1.25 + 3;
            mmaxHealth = level^1.25 + 3;
            mcritCahnce = level^1.25 + 3;
            mdodge = level^1.25 + 1;
        case 18: mname = "Leprechaun"
            mdamage = level^1.25 + 1;
            mmaxHealth = level^1.25 + 3;
            mcritCahnce = level^1.25 + 1;
            mdodge = level^1.25 + 5;
        case 19: mname = "Giant"
            mdamage = level^1.25 + 4;
            mmaxHealth = level^1.25 + 5;
            mcritCahnce = level^1.25 + 3;
            mdodge = level^1.25 + 1;
        case 20: mname = "Jeff's Mum"
            mdamage = level^1.25;
            mmaxHealth = level^1.25 + 5;
            mcritCahnce = level^1.25;
            mdodge = level^1.25 + 1;
    }
}

std::string Monster::getNameMonster() {
    //returns monsters name
    return mname;
}

int Monster::mDamageCalculator() {
    
}