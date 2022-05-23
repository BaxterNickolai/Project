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

    
    Combat(); //initalises the combat sequences by reseting the player
    void PreCombat(); //choses new monster to fight and then sets off fight()
    void fight(); //calculates the damages of the monster and player, based on randomness and what the player inputs from other combat functions
    void PostCombat(); //if player survives postCombat() is set off by fight where the player may increase xp / level
    int SelectMove(); //interface for the player to select move (light, medium, heavy, dodge)
    void UserInterface(); //happens at the very begining of when a combat is taking place to say who gets the first hit
    void Death(); //if monster or player health decreases past 0 then this function will change their health to 0 to display correctly
    void CritChance(); //calculates the critical chance of the monster and player
    
    int move; //the move selected by the player
    int hpPlayer; //the current hp of the player in combat
    Player *player; //the player int combat
    Monster *monster; //the monster in combat
    GameStats *gamestats; //the gamestats for the game
    int hpMonster; //the current hp of the monster in combat
    int state;
    int turncount; //how long a battle has been taking place by user turncount
    

};
#endif //COMBAT_H_