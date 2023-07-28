#ifndef PLAYERFACTORY_H
#define PLAYERFACTORY_H
#include "object.h"
#include "character.h"
#include "player.h"
#include "shade.h"
#include "troll.h"
#include "drow.h"
#include "vampire.h"
#include "goblin.h"
#include "position.h"

class PlayerFactory {
 public:
    static Player *createPlayer(char race, Position *pos);
};


#endif