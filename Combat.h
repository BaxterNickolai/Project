#ifndef COMBAT_H_
#define COMBAT_H_
#include <string>
#include <iostream>
#include "Player.h"
#include "Monster.h"
class Combat{
    public:
    Combat();
    void PreCombat();
    void PostCombat();
    void fight();
    int SelectMove();
    void UserInterface();
    int InputValidator(int, int);
    int hpPlayer;
    Player *player;
    Monster *monster;
    int hpMonster;
    int state;
    int turncount;
    
    
};
#endif //COMBAT_H_