#include "Combat.h"
#include "Player.h"
#include "Monster.h"
#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
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
    sleep(3);
    std::cout<<"You have slain the enemy!"<<std::endl<<"Enter anything to continue > ";
    int d;
    std::cin>>d;
    system("clear");
    hpPlayer = player->maxHealth;
    Combat::PreCombat();
}

void Combat::fight(){
    //while plyer is not dead player cna attack. after player attacks, monster also attacks if it is not dead, ending the turn
    system("clear");
    std::cout<<"A "<<monster->name<<" has appeared!"<<std::endl;
    Combat::UserInterface();
    while(1==1){
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
        sleep(3);
        if (0<move<4) {
            //if the player chooses to attack
            if (monster->dexterity>player->dexterity) {
                //if the monster has more dexterity stats than the player they attack first
                hpPlayer = hpPlayer-monster->damage;
                hpMonster = hpMonster-player->damage*move;
                if (turncount>0) {
                    std::cout<<"You dealt "<<player->damage*move<<" damage to the monster!"<<std::endl;
                    std::cout<<"The monster dealt "<<(monster->damage)<<" damage to you!"<<std::endl<<std::endl;
                }
                if (hpPlayer<0) {
                    hpPlayer = 0;
                } else if (hpMonster<0) {
                    hpMonster = 0;
                }
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
                if (turncount>0) {
                    std::cout<<"You dealt "<<player->damage*move<<" damage to the monster!"<<std::endl;
                    std::cout<<"The monster dealt "<<(monster->damage)<<" damage to you!"<<std::endl<<std::endl;
                }
                if (hpPlayer<0) {
                    hpPlayer = 0;
                } else if (hpMonster<0) {
                    hpMonster = 0;
                }
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
    while (1==1) {
        std::cout<<"What action do you want to take?"<<std::endl<<std::endl;
        std::cout<<"1    Light Attack"<<std::endl<<"2    Medium Attack"<<std::endl<<"3    Heavy Attack"<<std::endl<<"4    Attempt Dodge"<<std::endl<<std::endl<<"> ";
        int a = InputValidator();
        if (0<a<5) {
            system("clear");
            return a;
        } else {
            std::cout<<"Not a vaild input, enter number between 1 and 4."<<std::endl;
            //delay of 2 seconds
            sleep(2);
            int a = InputValidator();
        }
    }
    return 0;
}
int InputValidator(){
    int number;
    if (std::cin >> number) {
        break;
    } else {
        cout << "Please enter a valid integer" << endl;
        std::cin.clear();
        std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return n;
}