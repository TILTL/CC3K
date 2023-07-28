#ifndef RH_H
#define RH_H

#include "position.h"
#include "object.h"
#include "item.h"
#include "potion.h"

class RH : public Potion {
 public:
    RH(Position *pos);
};

#endif
