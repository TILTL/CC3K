#include "orc.h"

using namespace std;

Orc::Orc(Position *pos) {
    this->type = "orc";
    this->hp = 180;
    this->atk = 30;
    this->def = 25;
    this->pos = pos;
    this->isNeutral = false;
}

string Orc::attackPlayer(Player *opponent) {
    double magnify = 1.0;
    if(opponent->getType() == "goblin") {
        magnify = 1.5;
    }
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
    double amount = ((100.0 / (100.0 + pcDef)) * enemyAttack) * magnify;
    opponent->modifyHp(opponent->getHp() - amount);
    // get log
    combatInfo = attacker + " deals " + to_string(static_cast<int>(amount)) + " damage to PC, with 50% more damage.";
    return combatInfo;
}
