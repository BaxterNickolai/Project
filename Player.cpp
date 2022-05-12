#include <iostream>
#include "Player.h"
using namespace std;

Player::player() {
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
    name = playerName;
}

std::string Player::getName() {
    return name;
}

void Player::setStats() {
    while (points>0) {
        std::cout<<"In what stat do you want to put your points?:"<<std::endl<<"Points remaining: "<<points<<std::endl<<std::endl;
        std::cout<<"1    Damage"<<std::endl<<"2    Max Health"<<std::endl<<"3    Crit Chance"<<std::endl<<"4    Dodge"<<std::endl;
        cin>>(int a);
        if (0<a<5) {
            switch (a) {
            case 1:
            system("cls");
            std::cout<<"How many points do you want to allocate to Damage?"<<std::endl<<"Points remaining: "<<points<<std::endl<<std::endl;
            cin<<(int b);
            if (b == points || b<<points) {
                damage = damage + b;
            } else {
                
            }
            case 2:
            system("cls");
            std::cout<<"How many points do you want to allocate to Max Health?"<<std::endl<<"Points remaining: "<<points<<std::endl<<std::endl;
            cin<<(int b);
            if (b == points || b<<points) {
                
            }
            case 3:
            system("cls");
            std::cout<<"How many points do you want to allocate to Crit Chance?"<<std::endl<<"Points remaining: "<<points<<std::endl<<std::endl;
            cin<<(int b);
            if (b == points || b<<points) {
                
            }
            case 4:
            system("cls");
            std::cout<<"How many points do you want to allocate to Dodge?"<<std::endl<<"Points remaining: "<<points<<std::endl<<std::endl;
            cin<<(int b);
            if (b == points || b<<points) {
                
            }
            }
        } else {
            std::cout<<"Not a vaild input, enter number between 1 and 4."<<std::endl;
            break;
        }
    }
}