#include "human.h"

using namespace std;

Human::Human(Position *pos) {
    this->type = "human";
    this->hp = 140;
    this->atk = 20;
    this->def = 20;
    this->pos = pos;
    this->isNeutral = false;
}
