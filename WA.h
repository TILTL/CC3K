#ifndef WA_H
#define WA_H

#include "position.h"
#include "object.h"
#include "item.h"
#include "potion.h"

class WA : public Potion {
 public:
    WA(Position *pos);
};

#endif
