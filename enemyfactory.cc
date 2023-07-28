#include "enemyfactory.h"

Enemy *EnemyFactory::createEnemy(char &type, Position *pos) {
    int typeIdx = rand() % 18 + 1;
    if (typeIdx <= 4) {
        type = 'H';
        return new Human(pos);
    } else if (typeIdx <= 7) {
        type = 'W';
        return new Dwarf(pos);
    } else if (typeIdx <= 12) {
        type = 'L';
        return new Halfling(pos);
    } else if (typeIdx <= 14) {
        type = 'E';
        return new Elf(pos);
    } else if (typeIdx <= 16) {
        type = 'O';
        return new Orc(pos);
    } else {
        type = 'M';
        return new Merchant(pos);
    }
}
