#include "dragon.h"

Dragon::Dragon(Position *pos, DHoard *dhoard) {
    this->type = "dragon";
    this->hp = 150;
    this->atk = 20;
    this->def = 20;
    this->pos = pos;
    this->isNeutral = true;
    this->dhoard = dhoard;
}

void Dragon::freeHoard() {
    dhoard->freeGuard();
}

DHoard *Dragon::getDHoard() const {
    return this->dhoard;
}

void Dragon::setNeutral() {
    this->isNeutral = true;
}
