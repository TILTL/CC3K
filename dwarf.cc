#include "dwarf.h" 

Dwarf::Dwarf(Position *pos) {
    this->type = "dwarf";
    this->hp = 100;
    this->atk = 20;
    this->def = 30;
    this->pos = pos;
    this->isNeutral = false;
}

/*
string attackPlayerToVampire(Player *opponent) {
    int amount;
    int debuff = 5;
    string combatInfo;
    // participator
    string attacker = this->type;
    string defender = opponent->getType();
    // Atk
    int enemyAttack = this->atk;
    // Def
    int pcDef = opponent->getDef();
    // injure
    if (rand() % 2 == 0) {
        combatInfo = attacker + "missed attack. ";
        return combatInfo;
    }
    amount = (100 / (100 + pcDef)) * enemyAttack + debuff;
    opponent->modifyHp(amount);
    // get log
    combatInfo = attacker + " deals " + to_string(amount) + " damage to PC, with 5 more damage (DEBUFF)";
    return combatInfo;
}
*/

