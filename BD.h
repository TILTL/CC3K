#ifndef BD_H
#define BD_H

#include "position.h"
#include "object.h"
#include "item.h"
#include "potion.h"

class BD : public Potion {
 public:
    BD(Position *pos);
};

#endif
