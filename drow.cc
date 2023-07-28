#include "drow.h"

using namespace std;

Drow::Drow(int HP, int gold, Position *pos) {
    this->type = "drow";
    this->pos = pos;
    this->hp = HP;
    this->atk = 25;
    this->def = 15;
    this->maxHp = 150;
    this->gold = gold;
    this->defaultAtk = 25;
    this->defaultDef = 15;
}
