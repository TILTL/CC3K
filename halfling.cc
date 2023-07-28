#include "halfling.h"


Halfling::Halfling(Position *pos) {
    this->type = "halfing";
    this->hp = 100;
    this->atk = 15;
    this->def = 20;
    this->pos = pos;
    this->isNeutral = false;
}
