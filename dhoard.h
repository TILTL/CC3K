#ifndef DHOARD_H
#define DHOARD_H

#include "treasure.h"
#include "object.h"
#include "item.h"

using namespace std;


class DHoard : public Treasure {
 protected:
    bool isGuard;
 public:
    DHoard(Position *pos);
    bool getIsGuard();
    void freeGuard();
    ~DHoard() {}
    //DHoard();
};

#endif
