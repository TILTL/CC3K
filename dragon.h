#ifndef DRAGON_H
#define DRAGON_H

#include "enemy.h"
#include "dhoard.h"
#include "object.h"
#include "character.h"

using namespace std;

class Dragon : public Enemy {
    DHoard *dhoard;
 public:
    Dragon(Position *pos, DHoard *dhoard);
    ~Dragon() {}
    //char getType() override;
    void freeHoard();
    DHoard *getDHoard() const;
    void setNeutral();
};

#endif
