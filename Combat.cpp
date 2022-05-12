#include "Combat.h"
Combat::Combat(){
    hpPlayer = Player.maxHealth;
    hpMonster = Monster.maxHealth;
    turncount = 0;
}
void PreCombat