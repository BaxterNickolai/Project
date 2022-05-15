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

void Monster::setNameMonster() {
    int a = rand(1,20);
    switch (a) {
        case 1: mname = "Goblin"
        case 2: mname = "Golem"
        case 3: mname = "Assassin"
        case 4: mname = "Baron"
        case 5: mname = "Knight"
        case 6: mname = "Orc"
        case 7: mname = "Ogre"
        case 8: mname = "Paladin"
        case 9: mname = "Wisp"
        case 10: mname =  ""
        case 11: mname = 
        case 12: mname = 
        case 13: mname = 
        case 14: mname = 
        case 15: mname = 
        case 16: mname = 
        case 17: mname = 
        case 18: mname = 
        case 19: mname = 
        case 20: mname = "Jeff's Mum"
    }
    name = monsterName;
}

std::string Monster::getNameMonster() {
    //returns monsters name
    return name;
}

int Monster::mDamageCalculator() {
    
}