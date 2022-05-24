#ifndef COMBAT_H_
#define COMBAT_H_
#include <string>
#include <iostream>
#include "Player.h"
#include "Monster.h"
#include "GameStats.h"
class Combat{
    public:
    Combat(); //initalises the combat sequences by reseting the player
    void PreCombat(); //choses new monster to fight and then sets off fight()
    void fight(); //calculates the damages of the monster and player, based on randomness and what the player inputs from other combat functions
    void PostCombat(); //if player survives postCombat() is set off by fight where the player may increase xp / level
    int SelectMove(); //interface for the player to select move (light, medium, heavy, dodge)
    void UserInterface(); //happens at the very begining of when a combat is taking place to say who gets the first hit
    void Death(); //if monster or player health decreases past 0 then this function will change their health to 0 to display correctly
    void CritChance(); //calculates the critical chance of the monster and player
    void Dodge(); //function to calcul;ate whether dodge is successful
    
    int move; //the move selected by the player
    int monstermove; //move randomyl selected by the monster
    int hpPlayer; //the current hp of the player in combat
    Player *player; //the player int combat
    Monster *monster; //the monster in combat
    Monster *enemy;
    GameStats *gamestats; //the gamestats for the game
    int hpMonster; //the current hp of the monster in combat
    int turncount; //how long a battle has been taking place by user turncount
    

};
#endif //COMBAT_H_