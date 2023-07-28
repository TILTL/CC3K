#include "shade.h"

using namespace std;

Shade::Shade(int HP, int gold, Position *pos) {
    this->type = "shade";
    this->pos = pos;
    this->hp = HP;
    this->atk = 25;
    this->def = 25;
    this->maxHp = 125;
    this->gold = gold;
    this->defaultAtk = 25;
    this->defaultDef = 25;
}

    