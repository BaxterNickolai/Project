#include "Combat.h"
Combat::Combat(){
    //sets the initial current health of player and monster
    hpPlayer = Player.maxHealth;
    hpMonster = Monster.maxHealth;
    turncount = 0;
}
void PreCombat(int turncount){
    //set the spawn rate for each enemy
    int Gobchance = 50;
    int Trollchance = 30;
    int Vampchance = 19;
    int JeffsMomchance = 1;
    int n;
    //determines what enemy spawns
    int spawn = 1+( rand() % 51 );
    if(spawn>Vampchance&&spawn<Trollchance){
        Monseter Troll();
        n=1;
    }
    if(spawn>1&&spawn<Vampchance){
        Monseter Vampire();
        n=2;
    }
    if(spawn>Trollchance){
        Monster Goblin()
        n=3;
    }
    if(spawn==1;){
        Monseter JeffsMom();
        n=4;
    }
    
}
void PostCombat(int level){
    //gives the player xp after combat ends
    Player.xp++;
    int XPmax = 3*pow(1.2, level); 
    //allows player to level up
    if(Player.xp==XPmax){
        Player.xp = 0;
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
        
    }
}
int combat(){
    while(hpPlayer!=0){
        
    }
}