#ifndef NORMAL_H
#define NORMAL_H

#include "treasure.h"
#include "object.h"
#include "item.h"

using namespace std;

class Normal : public Treasure {
 public:
    Normal(Position *pos);
    Normal(Position *pos, int value);
    ~Normal() {}
};

#endif
