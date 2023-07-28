#include "itemfactory.h"
using namespace std;

// 0-RH,1-BA,2-BD,3-PH,4-WA,5-WD,6-normalgoldpile,7 - small hoard, 8 - merchant hoard, 9 - dragon hoard
char ItemFactory::itemTypes[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

Potion *ItemFactory::createPotion(char &type, Position *pos) {
        int typeIdx = rand() % 6;
        type = itemTypes[typeIdx];
        if (typeIdx == 0) {
            return new RH(pos);
        } else if (typeIdx == 1) {
            return new BA(pos);
        } else if (typeIdx == 2) {
            return new BD(pos);
        } else if (typeIdx == 3) {
            return new PH(pos);
        } else if (typeIdx == 4) {
            return new WA(pos);
        } else { 
            return new WD(pos);
        }
}

Treasure *ItemFactory::createTreasure(char &type, Position *pos) {
    int typeIdx = rand() % 8;
    if (typeIdx < 5) {
        type = itemTypes[6];
        return new Normal(pos);
    } else if (typeIdx < 7) {
        type = itemTypes[7];
        return new Small(pos);
    } else {
        type = itemTypes[9];
        return new DHoard(pos);
    }
}
