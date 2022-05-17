#include "Combat.h"
#include "Player.h"
#include "Monster.h"
#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <limits>
#include <cassert>
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
    hpPlayer = player->maxHealth;
    turncount = 0;
    std::cout<<"The monster spawned is: "<<monster->name<<std::endl;

    Combat::fight();
}

enum class StatType {
    maxHealth=1,
    damage,
    critChance,
    dexterity,
};

int RandRange(int min, int max){
    return min+(rand() %(max-min));
}

void Combat::PostCombat(){
    //gives the player xp after combat ends
    player->xp++;
    const int requiredXPbase = 1.2;
    const int requiredXPscale = 3;
    int XPmax = requiredXPscale*pow(requiredXPbase, player->level);
    assert(XPmax>0);
    //allows player to level up
    if(player->xp>=XPmax){
        player->xp -= XPmax;
        //randomly cooses what stat gets improved upon level up
        StatType selectedStat = (StatType) RandRange(1,4);
        assert((int)selectedStat>=1);
        assert((int)selectedStat<=4);
        player->level++;
        monster->level++;
        std::cout<<"You've leveled up! New level -> "<<player->level<<std::endl;
        
        switch (selectedStat){
            case StatType::maxHealth: player->maxHealth++;
                    std::cout<<"Maximum Health has increased: "<<player->maxHealth-1<<" -> "<<player->maxHealth<<std::endl<<std::endl;
                    break;
            case StatType::damage: player->damage++;
                    std::cout<<"Damage has increased: "<<player->damage-1<<" -> "<<player->damage<<std::endl<<std::endl;
                    break;
            case StatType::critChance: player->critChance++;
                    std::cout<<"Critical Chance has increased: "<<player->critChance-1<<" -> "<<player->critChance<<std::endl<<std::endl;
                    break;
            case StatType::dexterity: player->dexterity++;
                    std::cout<<"Dexterity has increased: "<<player->dexterity-1<<" -> "<<player->dexterity<<std::endl<<std::endl;
                    break;
        }
    }
    sleep(1);
    std::cout<<"You have slain the enemy!"<<std::endl<<"Enter anything to continue > ";
    int d;
    std::cin>>d;
    std::cin.clear();
    system("clear");
    std::cin.ignore(10000, '\n');
    Combat::PreCombat();
}

void Combat::fight(){
    //while plyer is not dead player cna attack. after player attacks, monster also attacks if it is not dead, ending the turn
    system("clear");
    std::cout<<"A "<<monster->name<<" has appeared!"<<std::endl;
    Combat::UserInterface();
    while(1==1){
        srand(time(NULL));
        if(hpPlayer < 1) {
            //if player is dead displays game over message, later to be replaced by some sort of end screen with stats
            std::cout<<"The "<<monster->name<<" killed you in battle!";
            break;
        } else if (hpMonster < 1) {
            Combat::PostCombat();
            break;
        }
        turncount++;
        int move = SelectMove();
        sleep(1);
        if (move==1 || move==2 || move==3) {
            //if the player chooses to attack
            if (monster->dexterity>player->dexterity) {
                //if the monster has more dexterity stats than the player they attack first
                if (CritChance() == 0) {
                    hpPlayer = hpPlayer-monster->damage*1.25;
                    hpMonster = hpMonster-player->damage*move;
                    if (turncount>0) {
                        std::cout<<"You dealt "<<player->damage*move<<" damage to the monster!"<<std::endl;
                        std::cout<<"The monster dealt a critical strike of "<<(monster->damage*1.25)<<" damage to you!"<<std::endl<<std::endl;
                    }
                } else if (CritChance() == 1) {
                    hpPlayer = hpPlayer-monster->damage;
                    hpMonster = hpMonster-player->damage*move*1.25;
                    if (turncount>0) {
                        std::cout<<"You dealt a critical strike of "<<player->damage*move*1.25<<" damage to the monster!"<<std::endl;
                        std::cout<<"The monster dealt "<<(monster->damage)<<" damage to you!"<<std::endl<<std::endl;
                    }
                } else {
                    hpPlayer = hpPlayer-monster->damage;
                    hpMonster = hpMonster-player->damage*move;
                    if (turncount>0) {
                        std::cout<<"You dealt "<<player->damage*move<<" damage to the monster!"<<std::endl;
                        std::cout<<"The monster dealt "<<(monster->damage)<<" damage to you!"<<std::endl<<std::endl;
                    }
                }
                Death();
                //interface that explains how much damage was taken and how much damage was dealt.
                std::cout<<"Player's Health      Monster's Health"<<std::endl;
                std::cout<<"("<<hpPlayer<<"/"<<player->maxHealth<<")                ("<<hpMonster<<"/"<<monster->maxHealth<<")"<<std::endl<<std::endl;
            } else {
                //otherwise the player attacks first
                hpMonster = hpMonster-player->damage*move;
                int damageDealt = player->damage*move;
                if(hpMonster>0){
                    hpPlayer = hpPlayer-monster->damage;
                }
                Death();
                if (turncount>0) {
                    std::cout<<"You dealt "<<player->damage*move<<" damage to the "<<monster->name<<"!"<<std::endl;
                    if(hpMonster>0){
                        std::cout<<"The "<<monster->name<<" dealt "<<(monster->damage)<<" damage to you!"<<std::endl<<std::endl;
                    }
                }
                //interface that explains how much damage was taken and how much damage was dealt.
                std::cout<<"Player's Health      Monster's Health"<<std::endl;
                std::cout<<"("<<hpPlayer<<"/"<<player->maxHealth<<")                ("<<hpMonster<<"/"<<monster->maxHealth<<")"<<std::endl<<std::endl;
            }
        } else {
            //if the player chooses to dodge
            //gives number between 0 and 100 chance for dodge for player and monster
            int playerDodgeChance = ((rand() % 25)+25)*log(player->dexterity);
            int monsterDodgeChance = ((rand() % 25)+25)*log(monster->dexterity);
            if (monsterDodgeChance>playerDodgeChance) {
                //need to add interface that explains how much damage was taken and how much damage was dealt.
                //monster attacks first and player looses its turn.
                std::cout<<"Your attempt to dodge has failed, losing your turn."<<std::endl;
                std::cout<<"The "<<monster->name<<" dealt "<<(monster->damage)<<" damage to you!"<<std::endl<<std::endl;
                hpPlayer = hpPlayer-monster->damage;
                Death();
                std::cout<<"Player's Health      Monster's Health"<<std::endl;
                std::cout<<"("<<hpPlayer<<"/"<<player->maxHealth<<")                ("<<hpMonster<<"/"<<monster->maxHealth<<")"<<std::endl<<std::endl;
            } else {
                //need to add interface that explains how much damage was taken and how much damage was dealt.
                //player attacks first and monster looses its turn.
                std::cout<<"Your attempt to dodge has succeeded!"<<std::endl;
                std::cout<<"You dealt "<<player->damage*move<<" damage to the monster!"<<std::endl<<std::endl;
                hpMonster = hpMonster-player->damage*move;
                Death();
                std::cout<<"Player's Health      Monster's Health"<<std::endl;
                std::cout<<"("<<hpPlayer<<"/"<<player->maxHealth<<")                ("<<hpMonster<<"/"<<monster->maxHealth<<")"<<std::endl<<std::endl;
            }
        }
    }
}

void Combat::UserInterface(){
    if (monster->dexterity>player->dexterity) {
        sleep(1);
        system ("clear");
        std::cout<<"The "<<monster->name<<" caught you off guard, attacking first and dealing "<<monster->damage<<" damage!"<<std::endl<<std::endl;
        hpPlayer = hpPlayer-monster->damage;
        if (hpPlayer<0) {
            hpPlayer = 0;
        }
        std::cout<<"Player's Health      Monster's Health"<<std::endl;
        std::cout<<"("<<hpPlayer<<"/"<<player->maxHealth<<")                ("<<hpMonster<<"/"<<monster->maxHealth<<")"<<std::endl<<std::endl;
    } else {
        sleep(2);
        std::cout<<"The "<<monster->name<<" is preparing to attack!"<<std::endl<<std::endl;
    }
}

int Combat::SelectMove(){
    int a = 0;
        std::cout<<"What action do you want to take?"<<std::endl<<std::endl;
        std::cout<<"1    Light Attack"<<std::endl<<"2    Medium Attack"<<std::endl<<"3    Heavy Attack"<<std::endl<<"4    Attempt Dodge"<<std::endl<<std::endl<<"> ";
        a = InputValidator(1,4);
        assert(a>0&&a<5);
        return a;
        system("clear");
            while(1!=2){
                int a = InputValidator(1,4);
                if (a!=0){
                    assert(a>0&&a<5);
                    return a;
                    system("clear");
                } else {
                std::cout<<"Not a vaild input, enter number between 1 and 4."<<std::endl;
                //delay of 2 seconds
                sleep(2);
                int a = Combat::InputValidator(1,4);
                }
            }
    return 0;
}

int Combat::InputValidator(int min, int max) {
    int input=0;
    while(1!=2){
        if(std::cin >> input&&input<=max&input>=min){
            break;
        }else{
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Not a valid input, please enter a number between "<<min<<" and "<<max<<std::endl;
        }
    }
    return input;
}

void Combat::Death() {
    if (hpPlayer<0) {
        hpPlayer = 0;
    } else if (hpMonster<0) {
        hpMonster = 0;
    }
}

int Combat::CritChance() {
    int monsterCritChance = ((rand() % 25)+25)*log(monster->critChance);
    int playerCritChance;
    if (move == 1) {
        int playerCritChance = ((rand() % 25)+35)*log(player->critChance);
    } else if (move == 2) {
        int playerCritChance = ((rand() % 25)+25)*log(player->critChance);
    } else {
        int playerCritChance = ((rand() % 25)+15)*log(player->critChance);
    }
    if (playerCritChance>monsterCritChance+10) {
        return 1;
    } else {
        return 0;
    }
    return 2;
}