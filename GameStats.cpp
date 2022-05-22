#include <iostream>
#include "GameStats.h"
#include "Combat.h"
//#include "Combat.h"
GameStats::GameStats(){
    monstersKilled = 0;
    playerCrits = 0;
    damageDealt = 0;
    level = 1;
}
void GameStats::printStats(){
    std::cout<<std::endl<<"Game Over"<<std::endl;
    std::cout<<"You have reached level "<<level<<std::endl;
    std::cout<<"You have killed "<<monstersKilled<<" monsters"<<std::endl;
    std::cout<<"You have dealt a total of "<<playerCrits<<" critical strikes"<<std::endl;
    std::cout<<"You have dealt a total of "<<damageDealt<<" damage"<<std::endl;
}