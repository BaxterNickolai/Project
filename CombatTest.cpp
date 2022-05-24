#include <iostream>
#include "Combat.h"
#include "Player.h"
#include "Monster.h"
#include "GameStats.h"
void test1(){
    Combat combat;
    std::cout<<"the health of the player is "<<combat.hpPlayer<<" this should be 50+5*points spent"<<std::endl;
    std::cout<<"the initial turncount is "<<combat.turncount<<" this should be 0 initially"<<std::endl;
}

void test2(){
    Combat combat;
    combat.PreCombat(); 
}

void test3(){
    Combat combat;
    Monster monster;
    combat.hpMonster = monster.maxHealth;
    combat.hpMonster = -50;
    combat.hpPlayer = -5;
    combat.Death();
    std::cout<<"hpMonster = "<<combat.hpMonster<<" should, reset to 0"<<std::endl<<"hpPlayer = "<<combat.hpPlayer<<" should be 0"<<std::endl;
}

int main(){
    test3();
}