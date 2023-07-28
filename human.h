#ifndef HUMAN_H
#define HUMAN_H

#include "enemy.h"
#include "object.h"
#include "character.h"

class Human : public Enemy {
 public:
    Human(Position *pos);
    ~Human() {}
};

#endif
