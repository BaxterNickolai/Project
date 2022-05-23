#include <iostream>
#include "GameStats.h"
#include "Combat.h"
//#include "Combat.h"
GameStats::GameStats(){
    //initalises the game stats for the run
    monstersKilled = 0;
    playerCrits = 0;
    damageDealt = 0;
    level = 1;
}
void GameStats::printStats(){
    // prints the stats collected from your game
    std::cout<<std::endl<<"Game Over"<<std::endl; //informs the player the game is over
    std::cout<<"You have reached level "<<level<<std::endl; //the level reached
    std::cout<<"You have killed "<<monstersKilled<<" monsters"<<std::endl; //the number of monsters killed
    std::cout<<"You have dealt a total of "<<playerCrits<<" critical strikes"<<std::endl; //the number of critical strikes dealt
    std::cout<<"You have dealt a total of "<<damageDealt<<" damage"<<std::endl; //the total damage dealt
}