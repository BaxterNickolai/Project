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
    level =1;
    name = "?"; 
}
Monster::Monster(int dmg, int hp, int crit, int dex, std::string mname)
//:damage(dmg), maxHealth(hp), critChance(crit), dexterity(dex), level(1), crit(1), name(mname)
{
    damage = dmg;
    maxHealth = hp;
    critChance = crit;
    dexterity = dex;
    crit = 1;
    name = mname;
}

Monster* Monster::createMonster(int level){
    //sets a new random value for the random function
    srand(time(NULL));
    //produces a random number between 1 and 20
    int monsterNumber = 1+( rand() % 20 );
    //dependent on the random number a pre-set monster is generated
    switch (monsterNumber) {
        case 1: 
            return new Monster(pow(level, 1.25) + 1, pow(level, 1.25) + 5,pow(level, 1.25) + 8,  pow(level, 1.25) + 5, "Goblin");
        case 2: 
            return new Monster(pow(level, 1.25) + 3, pow(level, 1.25) + 20,pow(level, 1.25) + 3,  pow(level, 1.25) + 1, "Golem");
        case 3: 
            return new Monster(pow(level, 1.25) + 5, pow(level, 1.25) + 6,pow(level, 1.25) + 20,  pow(level, 1.25) + 5, "Assassin");
        case 4: 
            return new Monster(pow(level, 1.25) + 3, pow(level, 1.25) + 30,pow(level, 1.25) + 1,  pow(level, 1.25) + 3, "Baron");
        case 5: 
            return new Monster(pow(level, 1.25) + 4, pow(level, 1.25) + 30,pow(level, 1.25) + 3,  pow(level, 1.25) + 1, "Knight");
        case 6: 
            return new Monster(pow(level, 1.25) + 2, pow(level, 1.25) + 20,pow(level, 1.25) + 5,  pow(level, 1.25) + 1, "Orc");
        case 7: 
            return new Monster(pow(level, 1.25) + 2, pow(level, 1.25) + 50,pow(level, 1.25) + 2,  pow(level, 1.25) + 1, "Ogre");
        case 8: 
            return new Monster(pow(level, 1.25) + 4, pow(level, 1.25) + 20,pow(level, 1.25) + 4,  pow(level, 1.25) + 2, "Paladin");
        case 9: 
            return new Monster(pow(level, 1.25) + 1, pow(level, 1.25) + 1,pow(level, 1.25) + 1,  pow(level, 1.25) + 1, "Wisp");
        case 10: 
            return new Monster(pow(level, 1.25) + 1, pow(level, 1.25) + 15,pow(level, 1.25) + 5,  pow(level, 1.25) + 3, "Mummy");
        case 11: 
            return new Monster(pow(level, 1.25) + 2, pow(level, 1.25) + 40,pow(level, 1.25) + 1,  pow(level, 1.25) + 2, "Wyvern");
        case 12: 
            return new Monster(pow(level, 1.25) + 10, pow(level, 1.25) + 10,pow(level, 1.25) + 15,  pow(level, 1.25) + 2, "Wizard");
        case 13: 
            return new Monster(pow(level, 1.25) + 5, pow(level, 1.25) + 50,pow(level, 1.25) + 12,  pow(level, 1.25) + 1, "Dragon");
        case 14: 
            return new Monster(pow(level, 1.25) + 1, pow(level, 1.25) + 10,pow(level, 1.25) + 1,  pow(level, 1.25) + 5, "Griffin");
        case 15: 
            return new Monster(pow(level, 1.25) + 1, pow(level, 1.25) + 50,pow(level, 1.25) + 1,  pow(level, 1.25) + 5, "Angel");
        case 16: 
            return new Monster(pow(level, 1.25) + 4, pow(level, 1.25) + 10,pow(level, 1.25) + 4,  pow(level, 1.25) + 1, "Demon");
        case 17: 
            return new Monster(pow(level, 1.25) + 3, pow(level, 1.25) + 30,pow(level, 1.25) + 3,  pow(level, 1.25) + 1, "Rock Elemental");
        case 18: 
            return new Monster(pow(level, 1.25) + 1, pow(level, 1.25) + 20,pow(level, 1.25) + 1,  pow(level, 1.25) + 5, "Leprechaun");
        case 19: 
            return new Monster(pow(level, 1.25) + 4, pow(level, 1.25) + 50,pow(level, 1.25) + 3,  pow(level, 1.25) + 1, "Giant");
        case 20: 
            return new Monster(pow(level, 1.25) , pow(level, 1.25) + 100,pow(level, 1.25) ,  pow(level, 1.25) , "Jeff's Mum");
    }
    return 0;
}
int Monster::SelectMove(){
    int move =1;
    srand(time(NULL)); //gives number between 0 and 100 chance for dodge for player and monster
    move = ((rand() % 3)+1);
    return move; //returns number
}