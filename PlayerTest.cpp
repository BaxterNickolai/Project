#include <iostream>
#include "Player.h"
int main(){
    {
        Player player;
        if(player.damage!=1||player.maxHealth!=50||player.critChance!=1||player.dexterity!=1||player.xp!=0||player.level!=1||player.name!="?"){
            std::cout<<"PlayerTest 1 failed";
        }
    }
    
    {
        Player player;
        player.selectStat();
        if (selectedStat<1||selectedStat>4) {
            std::cout<<"PlayerTest 2 failed"
        }
    }
    
    {
        Player player;
        player.selectNum(2);
        if (statName!="maxHealth") {
            std::cout<<"PlayerTest 3 failed";
        }
        if (points!=10-selectedNum) {
            std::cout<<"PlayerTest 4 failed";
        }
    }
    
    {
        Player player;
        player.SelectMove();
        if (move>4||move<1) {
            std::cout<<"PlayerTest 5 failed";
        }
    }
}