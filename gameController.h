#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "player.h"
#include "floor.h"
#include "display.h"
#include "display.h"
#include "floor.h"
#include <iostream>
using namespace std;

class GameController {
   Floor *floor;
   Display *display;
   string status;
 
 public:
   GameController(): floor(new Floor), display(new Display) {}
   void start(); 
   void readCommand(string input); //cope with commands
   void nextFloor();
   bool validDirection(string input) const;
   ~GameController(){ delete floor; delete display; }
   Floor *getFloor() const;
   string getStatus() const;
   Display *getDisplay() const;
};

#endif
