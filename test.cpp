void Combat::fight(){
    //while plyer is not dead player cna attack. after player attacks, monster also attacks if it is not dead, ending the turn
    system("clear");
    std::cout<<"A "<<monster->name<<" has appeared!"<<std::endl;
    Combat::UserInterface();
    while(1==1){
        Combat::CritChance();
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
        system("clear");
        if (move<4){
            if (monster->dexterity>player->dexterity) {
                hpPlayer = hpPlayer-monster->damage*1.25*monster->crit;
                hpMonster = hpMonster-player->damage*move*player->crit;
                Death();
            }
            else{
                //otherwise the player attacks first
                hpMonster = hpMonster-player->damage*move*player->crit;
                if(hpMonster>0){
                    hpPlayer = hpPlayer-monster->damage*monster->crit;
                }
                Death();
            }
            std::cout<<"You dealt ";
            if(player->crit==2){
                std::cout<<"a critical strike of ";
            }
            std::cout<<player->damage*move<<" damage to the "<<monster->name;
            if(hpMonster<1){
                std::cout<<"The monster dealt ";
                if(monster->crit==2){
                    std::cout<<"a critical strike of";
                }
                std::cout<<monster->damage*monster->crit<<" to you";
            }
        }
        else {
            //if the player chooses to dodge
            //gives number between 0 and 100 chance for dodge for player and monster
            srand(time(NULL));
            int playerDodgeChance = ((rand() % 25)+25)*log(player->dexterity);
            int monsterDodgeChance = ((rand() % 25)+25)*log(monster->dexterity);
            if (monsterDodgeChance>playerDodgeChance) {
                //monster attacks first and player looses its turn.
                std::cout<<"Your attempt to dodge has failed, losing your turn."<<std::endl;
                std::cout<<"The "<<monster->name<<" dealt "<<(monster->damage)<<" damage to you!"<<std::endl<<std::endl;
                hpPlayer = hpPlayer-monster->damage;
                Death();
            } else {
                //need to add interface that explains how much damage was taken and how much damage was dealt.
                //player attacks first and monster looses its turn.
                std::cout<<"Your attempt to dodge has succeeded!"<<std::endl<<"You counterattack, dealing "<<player->damage*move<<" damage to the monster!"<<std::endl<<std::endl;
                hpMonster = hpMonster-player->damage*1.5;
                Death();
            }
        }
        //interface that explains how much damage was taken and how much damage was dealt.
        std::cout<<"Player's Health      Monster's Health"<<std::endl;
        std::cout<<"("<<hpPlayer<<"/"<<player->maxHealth<<")                ("<<hpMonster<<"/"<<monster->maxHealth<<")"<<std::endl<<std::endl;
    }
}


void Combat::CritChance() {
    srand(time(NULL));
    monster->crit = 1;
    player->crit = 1;
    if((rand() % monster->critChance)>(rand() % 10)){
        monster->crit = 2;
    }
    if((rand() % player->critChance)>(rand() % 10)){
        player->crit = 2;
    }
}