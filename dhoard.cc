#include "dhoard.h"

DHoard::DHoard(Position *pos) {
    this->pos = pos;
    this->type = "dragon hoard";
    this->value = 6;
    this->isGuard = true;
}

void DHoard::freeGuard() {
    this->isGuard = false;
}

bool DHoard::getIsGuard() {
    return this->isGuard;
}

