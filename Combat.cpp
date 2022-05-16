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
    std::cout<<"damage: "<<player->damage<<std::endl<<"health: "<<player->maxHealth<<std::endl<<"crit chance: "<<player->critChance<<std::endl<<"dexterity: "<<player->dexterity<<std::endl;
}

void Combat::PreCombat(){
    //creates a monster object
    monster = new Monster;
    //chooses what monster is spawned
    monster->setMonster();
    hpMonster = monster->maxHealth;
    std::cout<<"The monster spawned is: "<<monster->name<<std::endl; 

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
            case 4: player->dexterity++;
            break;
        }
        player->level++;
        
    }
}

void Combat::fight(){
    //while plyer is not dead player cna attack. after player attacks, monster also attacks if it is not dead, ending the turn
    while(hpPlayer>0){
        turncount++;
        Combat::UserInterface();
        int move = SelectMove();
        if (0<move<4) {
            //if the player chooses to attack
            if (monster->dexterity>player->dexterity) {
                //if the monster has more dexterity stats than the player they attack first
                hpPlayer = hpPlayer-monster->damage;
                hpMonster = hpMonster-player->damage*move;
                //need to add interface that explains how much damage was taken and how much damage was dealt.
            } else {
                //otherwise the player attacks first
                hpMonster = hpMonster-player->damage*move;
                int damageDealt = player->damage*move;
                if(hpMonster>0){
                    hpPlayer = hpPlayer-monster->damage;
                }
                //need to add interface that explains how much damage was taken and how much damage was dealt.
            } 
        } else {
            //if the player chooses to dexterity
            //gives number between 0 and 100 chnces for player and monster
            int playerChance = ((rand() % 25)+25)*log(player->dexterity);
            int monsterChance = ((rand() % 25)+25)*log(monster->dexterity);
            if (monsterChance>playerChance) {
                //need to add interface that explains how much damage was taken and how much damage was dealt.
                //monster attacks first and player looses its turn.
            } else {
                //need to add interface that explains how much damage was taken and how much damage was dealt.
                //player attacks first and monster looses its turn.
            }
            
            
        }
        if(hpPlayer < 1) {
            //if player is dead displays game over message, later to be replaced by some sort of end screen with stats
            std::cout<<"game over";
            break;
        } else if (hpMonster < 1) {
            Combat::PostCombat();
            break;
        }
    }
}

void Combat::UserInterface(){
    system("clear");
    std::cout<<"A "<<monster->name<<" has appeared!"<<std::endl;
    if (monster->dexterity>player->dexterity) {
        sleep(1);
        system ("clear")
        std::cout<<"The "<<monster->name<<" caught you off guard, attacking first and dealing "<<monster-damage<<" damage!"<<std::endl<<std::endl;
    } else {
        sleep(2);
        std::cout<<"The "<<monster->name<<" is preparing to attack!"<<std::endl<<std::endl;
    }
}

int Combat::SelectMove(){
    while (1==1) {
        std::cout<<"What action do you want to take?"<<std::endl<<std::endl;
        std::cout<<"1    Light Attack"<<std::endl<<"2    Medium Attack"<<std::endl<<"3    Heavy Attack"<<std::endl<<"4    Attempt dexterity"<<std::endl<<std::endl<<"> ";
        int a;
        std::cin>>a;
        if (0<a<5) {
            switch (a) {
            case 1:
            system("clear");
            return 1;
            break;
            case 2:
            system("clear");
            return 2;
            break;
            case 3:
            system("clear");
            return 3;
            break;
            case 4:
            system("clear");
            return 4;
            break;
            }
        break;
        } else {
            std::cout<<"Not a vaild input, enter number between 1 and 4."<<std::endl;
            //delay of 2 seconds
            sleep(2);
        }
    }
}