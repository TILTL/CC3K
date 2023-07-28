#ifndef DISPLAY_H
#define DISPLAY_H

#include "panel.h"
#include <memory>
#include <string>
#include <iostream>
#include "floor.h"
using namespace std;

class Display {
    Floor *floor;
    string action = "Welcome! ";
 public:
    Display(): floor(new Floor) {}
    void printMap(Floor *floor) const;
    void printPanel(Floor *floor);
    void printPCInfo();
    void printLose();
    void printWin();
    string getAction() const;
    void setAction(string ac);
};

#endif
