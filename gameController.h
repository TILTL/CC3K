#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "player.h"
#include "floor.h"
#include "display.h"
#include "display.h"
#include "floor.h"
#include <iostream>
#include <memory>
using namespace std;

class GameController {
   unique_ptr<Floor> floor;
  unique_ptr<Display> display;
   string status;
   bool canRandomMove = true;
 
 public:
   GameController(): floor(new Floor), display(new Display) {}
   void start(); 
   void readCommand(string input); 
   bool validDirection(string input) const;
   Floor *getFloor() const;
   Display *getDisplay() const;
   string getStatus() const;
   ~GameController(){}
};

#endif
