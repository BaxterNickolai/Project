#ifndef COMBAT_H_
#define COMBAT_H_
#include <string>
#include <iostream>
#include "Player.h"
#include "Monster.h"
#include "GameStats.h"
class Combat{
    public:
    Combat();
    void PreCombat();
    void PostCombat();
    void fight();
    int SelectMove();
    void UserInterface();
    int InputValidator(int, int);
    void Death();
    void CritChance();
    int move;
    int hpPlayer;
    Player *player;
    Monster *monster;
    GameStats *gamestats; 
    int hpMonster;
    int state;
    int turncount;
};
#endif //COMBAT_H_