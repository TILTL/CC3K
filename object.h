#ifndef OBJECT_H
#define OBJECT_H

#include <string>
#include "position.h"

using namespace std;

class Object {
 protected:
  Position *pos;
  string type;
 public:
  virtual ~Object() = 0;
  void setPos(Position *pos);
  Position *getPos();
  string getType() const;
  bool playerWithinRange(Position *playerPos);
};

#endif
