#ifndef ITEMFACTORY_H
#define ITEMFACTORY_H

#include "potion.h"
#include "item.h"
#include "treasure.h"
#include "small.h"
#include "dhoard.h"
#include "normal.h"
#include "RH.h"
#include "BA.h"
#include "BD.h"
#include "PH.h"
#include "WA.h"
#include "WD.h"

class ItemFactory {
    static char itemTypes[10];
    
 public:
    ItemFactory();
    ~ItemFactory() {}
    static Potion *createPotion(char &type, Position *pos);
    static Treasure *createTreasure(char &type, Position *pos);
};

#endif