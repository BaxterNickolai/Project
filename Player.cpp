#include <iostream>
#include "Player.h"
#include <math.h>
#include <unistd.h>
#include <stdlib.h>
using namespace std;

Player::Player() {
    //initalising the starting values for the attributes contained in Player.h
    name = "?";
    damage = 1;
    maxHealth = 1;
    critChance = 1;
    dodge = 1;
    xp = 0;
    level = 1;
    points = 10;
}

void Player::setName(std::string playerName) {
    //gives the player their name depending on their input from the main funciton
    name = playerName;
}

std::string Player::getName() {
    //returns the player name
    return name;
}

void Player::setStats() {
    //while the points available to give to the players stats is greater than 0, therefore when there are still points to allocate
    while (points>0) {
        //clear console
        system("clear");
        //where does the user want to put the points
        std::cout<<"In what stat do you want to put your points?:"<<std::endl<<"Points remaining: "<<points<<std::endl<<std::endl;
        std::cout<<"1    Damage"<<std::endl<<"2    Max Health"<<std::endl<<"3    Crit Chance"<<std::endl<<"4    Dodge"<<std::endl<<std::endl<<"> ";
        //takes in user input
        int a;
        std::cin>>a;
        //if the user input is in the given range then the switch activates
        if (0<a<5) {
            //switch for 4 possible user inputs
            int b;
            switch (a) {
            case 1:
            //clear console and accept user input for how many points to allocate
            system("clear");
            std::cout<<"How many points do you want to allocate to Damage?"<<std::endl<<"Points remaining: "<<points<<std::endl<<std::endl<<"> ";
            std::cin>>b;
            //if statement for if points wanting to allocate are within the amount of points remaining or 0
            if (b <= points && b >= 0) {
                damage = damage + b;
                points = points - b;
            } else {
                std::cout<<"Invalid amount of points attempting to allocate, going back to main screen"<<std::endl;
                //delay of 3 seconds
                sleep(3);
                break;
            }
            break;
            case 2:
            //clear console and accept user input for how many points to allocate
            system("clear");
            std::cout<<"How many points do you want to allocate to Max Health?"<<std::endl<<"Points remaining: "<<points<<std::endl<<std::endl<<"> ";
            std::cin>>b;
            //if statement for if points wanting to allocate are within the amount of points remaining or 0
            if (b <= points && b >= 0) {
                maxHealth = maxHealth + b;
                points = points - b;
            } else {
                std::cout<<"Invalid amount of points attempting to allocate, going back to main screen"<<std::endl;
                //delay of 3 seconds
                sleep(3);
                break;
            }
            break;
            case 3:
            //clear console and accept user input for how many points to allocate
            system("clear");
            std::cout<<"How many points do you want to allocate to Crit Chance?"<<std::endl<<"Points remaining: "<<points<<std::endl<<std::endl<<"> ";
            std::cin>>b;
            //if statement for if points wanting to allocate are within the amount of points remaining or 0
            if (b <= points && b >= 0) {
                critChance = critChance + b;
                points = points - b;
            } else {
                std::cout<<"Invalid amount of points attempting to allocate, going back to main screen"<<std::endl;
                //dealy of 3 seconds
                sleep(3);
                break;
            }
            break;
            case 4:
            //clear console and accept user input for how many points to allocate
            system("clear");
            std::cout<<"How many points do you want to allocate to Dodge?"<<std::endl<<"Points remaining: "<<points<<std::endl<<std::endl<<"> ";
            std::cin>>b;
            //if statement for if points wanting to allocate are within the amount of points remaining or 0
            if (b <= points && b >= 0) {
               dodge = dodge + b;
               points = points - b;
            } else {
                std::cout<<"Invalid amount of points attempting to allocate, going back to main screen"<<std::endl;
                //delay of 3 seconds
                sleep(3);
                break;
            }
            break;
            }
        } else {
            std::cout<<"Not a vaild input, enter number between 1 and 4."<<std::endl;
            //delay of 3 seconds
            sleep(3);
        }
    }
}