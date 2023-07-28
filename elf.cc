#include "elf.h"

Elf::Elf(Position *pos) {
    this->type = "elf";
    this->hp = 140;
    this->atk = 30;
    this->def = 10;
    this->pos = pos;
    this->isNeutral = false;
}

string Elf::attackPlayer(Player *opponent) {
    int amount;
    int numAttack = 2;
    string combatInfo;
    // participator
    string attacker = this->type;
    string defender = opponent->getType();
    // Atk
    int enemyAttack = this->atk;
    // Def
    int pcDef = opponent->getDef();
    if (opponent->getType() == "drow") {
        numAttack = 1;
    }
    for(int i = 0; i < numAttack; i++) {
        // injure
        if (rand() % 2 == 0) {
            combatInfo += attacker + "Missed attack. ";
        } else {
            amount = (100 / (100 + pcDef)) * enemyAttack;
            opponent->modifyHp(opponent->getHp() - amount);
            combatInfo += attacker + " deals " + to_string(amount) + " damage to PC";
        }
    }
    return combatInfo;
}
