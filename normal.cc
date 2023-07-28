#include "normal.h"

Normal::Normal(Position *pos) {
    this->pos = pos;
    this->type = "normal";
    this->value = 2;
    //this->isGuard = false;
} 

Normal::Normal(Position *pos, int value) {
    this->pos = pos;
    this->type = "merchant hoard";
    this->value = value;
}
