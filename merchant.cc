#include "merchant.h"

using namespace std;

Merchant::Merchant(Position *pos) {
    this->type = "merchant";
    this->hp = 30;
    this->atk = 70;
    this->def = 5;
    this->pos = pos;
    this->isNeutral = true;
}

/*
void Merchant::notNeutral() {
    this->isNeutral = false;
}
*/
