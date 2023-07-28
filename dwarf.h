#ifndef DWARF_H
#define DWARF_H

#include "enemy.h"
#include "object.h"
#include "character.h"


class Dwarf : public Enemy {
    //DHoard *dhoard;
 public:
    Dwarf(Position *pos);
    ~Dwarf() {}
    //string attackPlayerToVampire(Player *opponent);
};

#endif
