#ifndef WD_H
#define WD_H

#include "position.h"
#include "object.h"
#include "item.h"
#include "potion.h"

class WD : public Potion {
 public:
    WD(Position *pos);
};

#endif
