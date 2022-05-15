#ifndef COMBAT_H_
#define COMBAT_H_
#include <string>
#include <iostream>
#include "Player.h"
#include "Monster.h"
class Combat{
    public:
    Combat();
    int hpPlayer;
    Player *player;
    Monster *monster;
    int hpMonster;
    int state;
    int turncount;
    void PreCombat();
    void PostCombat();
    void fight();
    int SelectMove();
    void UserInterface();
    
    
};
#endif //COMBAT_H_