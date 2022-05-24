#include <iostream>
#include "Player.h"
#include <math.h>
#include "Combat.h"
#include <unistd.h>
#include <stdlib.h>
using namespace std;

Player::Player() {
    //initalising the starting values for the attributes contained in Player.h
    name = "?";
    damage = 1;
    maxHealth = 50;
    critChance = 1;
    dexterity = 1;
    xp = 0;
    level = 1;
    points = 10;
}

void Player::setStats() {
    //while the points available to give to the players stats is greater than 0, therefore when there are still points to allocate
    while (points>0) {
        int stat = selectStat();
        //switch for 4 possible user inputs
        selectNum(stat);
    }
}
int Player::selectStat(){
    //clear console
    system("clear");
    //where does the user want to put the points
    std::cout<<"In what stat do you want to put your points?:"<<std::endl<<"Points remaining: "<<points<<std::endl<<std::endl;
    std::cout<<"1    Damage"<<std::endl<<"2    Max Health"<<std::endl<<"3    Crit Chance"<<std::endl<<"4    Dexterity"<<std::endl<<std::endl<<"> ";
    int selectedStat;
    selectedStat = InputValidator(1,4);
    //returns stat selected
    return selectedStat;
}
void Player::selectNum(int stat){
    //clear console
    system ("clear");
    std::string statName = ".";
    switch (stat) {
        case 1:statName = "Damage";
        break;
        case 2:statName = "Max Health";
        break;
        case 3:statName = "Crit Chance";
        break;
        case 4:statName = "Dexterity";
        break;
    }
    //how many points does the user want to allocate to a stat
    std::cout<<"How many points do you want to allocate to "<<statName<<"?"<<std::endl<<"Points remaining: "<<points<<std::endl<<std::endl<<"> ";
    int selectedNum;
    selectedNum = InputValidator(0,points);
    switch (stat){
        case 1: //if damage chosen
        damage = damage+selectedNum;
        points = points-selectedNum;
        break;
    case 2: //if max health chosen
        maxHealth = maxHealth+selectedNum*5;
        points = points-selectedNum;
        break;
    case 3: //if crit chance chosen
        critChance = critChance+selectedNum;
        points = points-selectedNum;
        break;
    case 4: //if dexterity chosen
        dexterity = dexterity+selectedNum;
        points = points-selectedNum;
        break;
    }
}


int Player::InputValidator(int min, int max) {
    //function to validate the inputs from the user into the game
    int input=0;
    while(1!=2){
        if(std::cin >> input&&input<=max&input>=min) {
            //if a valid input
            break;
        } else {
            //if not a valid input
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Not a valid input, please enter a number between "<<min<<" and "<<max<<std::endl;
            sleep(2);
        }
    }
    //returns the input
    return input;
}
int Player::SelectMove(){
    int move = 0; //number to hold what attack the player wants to take
    std::cout<<"What action do you want to take?"<<std::endl<<std::endl;
    std::cout<<"1    Light Attack"<<std::endl<<"2    Medium Attack"<<std::endl<<"3    Heavy Attack"<<std::endl<<"4    Attempt Dodge"<<std::endl<<std::endl<<"> ";
    move = InputValidator(1,4); //validates that a is a recievable number
    return move; //returns number
}