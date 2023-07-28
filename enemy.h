#ifndef ENEMY_H
#define ENEMY_H

#include "player.h"
#include "character.h"

using namespace std;

class Player;

class Enemy : public Character {
 protected:
    bool isNeutral;
    //int chamberID;
 public:
    virtual string attackPlayer(Player *opponent);
    bool getIsNeutral() const;
    Position move();
    void notNeutral();
    //virtual void notGuard();
};

#endif
