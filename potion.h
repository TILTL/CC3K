#ifndef POTION_H
#define POTION_H

#include <string>
#include "item.h"
#include "position.h"
#include "object.h"
using namespace std;


class Potion : public Item {
    //string potionType;
    //Player *player;
 public:
    Potion() {}
    virtual ~Potion() = 0;
};

#endif
