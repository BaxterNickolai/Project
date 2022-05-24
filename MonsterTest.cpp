#include <iostream>
#include "Monster.h"
int main(){
    
    {
    Monster monster;
        if(monster.damage!=0||monster.maxHealth!=0||monster.critChance!=0||monster.dexterity!=0||monster.name!="?"){
            std::cout<<"MonsterTest 1 failed";
        }
    }

    {
    Monster monster (1,2,3,4,"testname");
        if(monster.damage!=1||monster.maxHealth!=2||monster.critChance!=3||monster.dexterity!=4||monster.name!="testname"){
            std::cout<<"MonsterTest 2 failed";
        }
    }
    
    {
        Monster enemy;
        Monster *monster=enemy.Monster::createMonster(1);
        std::cout<<"selected monster is "<<monster->name<<", should be randomly chosen from the monsters"<<std::endl;
        std::cout<<"health of selected monster at level 1 is: "<<monster->maxHealth<<std::endl;
    }
    
    {
        Monster monster;
        std::cout<<"selected move is : "<<monster.SelectMove()<<", should be randomly between 1 and 3"<<std::endl;
    }
    
    
    
    return 0;
}