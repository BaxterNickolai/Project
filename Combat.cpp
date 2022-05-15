#include "Combat.h"
#include "Player.h"
#include "Monster.h"
#include <iostream> 
#include <math.h>
Combat::Combat(){
    //sets the initial current health of player
    player = new Player;
    player->setStats();
    hpPlayer = player->maxHealth;
    turncount = 0;
    player->setStats();
    //temporary test to see if setstats works correctly
    std::cout<<"damage: "<<player->damage<<std::endl<<"health: "<<player->maxHealth<<std::endl<<"crit chance: "<<player->critChance<<std::endl<<"dodge: "<<player->dodge<<std::endl;
}
void Combat::PreCombat(){
    //creates a monster object
    monster = new Monster;
    //chooses what monster is spawned
    monster->setMonster();
    hpMonster = monster->maxHealth;
    std::cout<<"The monster spawned is: "<<monster->mname<<std::endl; 

}
void Combat::PostCombat(){
    //gives the player xp after combat ends
    player->xp++;
    int XPmax = 3*pow(1.2, player->level); 
    //allows player to level up
    if(player->xp==XPmax){
        player->xp = 0;
        //randomly cooses what stat gets improved upon level up
        int stat = 1+( rand() % 5 );
        switch (stat){
            case 1: player->maxHealth++;
            break;
            case 2: player->damage++;
            break;
            case 3: player->critChance++;
            break;
            case 4: player->dodge++;
            break;
        }
        player->level++;
        
    }
}
void Combat::fight(){
    //while plyer is not dead player cna attack. after player attacks, monster also attacks if it is not dead, ending the turn
    while(hpPlayer!=0){
        turncount++;
        Combat::UserInterface();
        int move = SelectMove();
        hpMonster = hpMonster-player->damage*move;
        int damageDealt = player->damage*move;
        if(hpMonster>0){
            hpPlayer = hpPlayer-monster->damage;
        }
        
    }
    //if player is dead displays game over message, later to be replaced by some sort of end screen with stats
    if(hpPlayer <1){
        std::cout<<"game over";
    }
    //if player is not dead, post combat activates, allowing player to level up and stuff. Postcombat then initiates precombat again, starting a new fight
    else{
        Combat::PostCombat();
    }
}

void Combat::UserInterface(){
    //
}
int Combat::SelectMove(){
    return 1;
}