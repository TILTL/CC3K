#ifndef ORC_H
#define ORC_H

#include "enemy.h"
#include "object.h"
#include "character.h"

using namespace std;


class Orc : public Enemy {
 public:
    Orc(Position *pos);
    ~Orc() {}
    string attackPlayer(Player *opponent) override;
};

#endif
