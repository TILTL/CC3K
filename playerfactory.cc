#include "playerfactory.h"

Player *PlayerFactory::createPlayer(char race, Position *pos) {
        if (race == 's') {
            return new Shade(125, 0, pos);
        } else if (race == 'd') {
            return new Drow(150, 0, pos);
        } else if (race == 'v') {
            return new Vampire(50, 0, pos);
        } else if (race == 't') {
            return new Troll(120, 0, pos);
        } else {
            return new Goblin(110, 0, pos);
        }
    }