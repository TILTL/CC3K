#ifndef SMALL_H
#define SMALL_H

#include "treasure.h"
#include "object.h"
#include "item.h"

using namespace std;


class Small : public Treasure {
 public:
    Small(Position *pos);
    ~Small() {}
};

#endif
