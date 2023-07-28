#ifndef MERCHANT_H
#define MERCHANT_H

#include "enemy.h"
#include "object.h"
#include "character.h"

using namespace std;

class Merchant : public Enemy {
    //bool isHostile;
 public:
    Merchant(Position *pos);
    //void notNeutral();
    ~Merchant() {}
};

#endif
