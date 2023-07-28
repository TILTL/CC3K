#include "goblin.h"

using namespace std;

Goblin::Goblin (int HP, int gold, Position *pos) {
    this->type = "goblin";
    this->pos = pos;
    this->hp = HP;
    this->atk = 15;
    this->def = 20;
    this->maxHp = 110;
    this->gold = gold;
    this->defaultAtk = 15;
    this->defaultDef = 20;
}
