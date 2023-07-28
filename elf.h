#ifndef ELF_H
#define ELF_H

#include "enemy.h"
#include "object.h"
#include "character.h"


class Elf : public Enemy {
 public:
    Elf(Position *pos);
    ~Elf() {}
    //string attackPlayerX2(Player *opponent);
    string attackPlayer(Player *opponent) override;
};
    
#endif
