#include "Combat.h"
#include "Player.h"
#include "Monster.h"
Combat::Combat(){
    //sets the initial current health of player
    Player player();
    hpPlayer = player.maxHealth;
    turncount = 0;
    
}
Combat::PreCombat(){
    //set the spawn rate for each enemy
    int Gobchance = 100;
    int Trollchance = 50;
    int Vampchance = 30;
    int JeffsMomchance = 1;
    int n;
    //determines what enemy spawns
    int spawn = 1+( rand() % 101 );
    if(spawn>Vampchance&&spawn<Trollchance){
        Monseter monster("Troll", 1);
        n=1;
    }
    if(spawn>1&&spawn<Vampchance){
        Monseter monster("Vampire", 2);
        n=2;
    }
    if(spawn>Trollchance){
        Monster monster("Goblin", 3)
        n=3;
    }
    if(spawn==1;){
        Monseter monster("JeffsMom", 4);
        n=4;
    }
    hpMonster = monster.maxHealth;

}
Combat::PostCombat(int level){
    //gives the player xp after combat ends
    Player.xp++;
    int XPmax = 3*pow(1.2, level); 
    //allows player to level up
    if(player.xp==XPmax){
        player.xp = 0;
        //randomly cooses what stat gets improved upon level up
        int stat = 1+( rand() % 5 );
        switch (stat){
            case 1: Player.maxHealth++;
            break;
            case 2: Player.damage++;
            break;
            case 3: Player.critChance++;
            break;
            case 4: PLayer.dodge++;
            break;
        }
        Player.level++;
        
    }
}
Combat::fight(){
    //while plyer is not dead player cna attack. after player attacks, monster also attacks if it is not dead, ending the turn
    while(hpPlayer!=0){
        turncount++;
        Combat::UI();
        int move = Combat.selectMove();
        hpMonster = hpMonster-player.damage*move;
        int damageDealt = player.damage*move;
        if(hpMonster>0){
            hpPlayer = hpPlayer-monster.damage;
        }
        
    }
    //if player is dead displays game over message, later to be replaced by some sort of end screen with stats
    if(hpPlayer <1;){
        std::cout<<"game over";
    }
    //if player is not dead, post combat activates, allowing player to level up and stuff. Postcombat then initiates precombat again, starting a new fight
    else{
        Combat.PostCombat(player.level);
    }
}