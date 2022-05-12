#ifndef COMBAT_H_
#define COMBAT_H_
#include <string>
#include <iostream>
class Combat{
    public:
    Combat();
    int hpPlayer;
    int hpMonster;
    int state;
    int turncount;
    void PreCombat();
    void PostCombat();
    int fight();
    int selectMove();
    
    
}