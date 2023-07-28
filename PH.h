#ifndef PH_H
#define PH_H

#include "position.h"
#include "object.h"
#include "item.h"
#include "potion.h"

class PH : public Potion {
  public:
    PH(Position *pos);
};

#endif