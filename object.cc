#include "object.h"
#include "position.h"
using namespace std;

using namespace std;

void Object::setPos(Position *pos) {
    this->pos = pos;
}

Position *Object::getPos() {
	return this->pos;
}


/*
Position Object::newPos(string dir) {
    Position p = pos;
	int x = p.getX();
	int y = p.getY();
    if (dir == "no") {
		p.setPos(x, y + 1);
	} else if (dir == "so") {
		p.setPos(x, y - 1);
	} else if (dir == "we") {
		p.setPos(x - 1, y);
	} else if (dir == "ea") {
		p.setPos(x + 1, y);
	} else if (dir == "ne") {
		p.setPos(x + 1, y - 1);
	} else if (dir == "nw") {
		p.setPos(x - 1, y - 1);
	} else if (dir == "se") {
		p.setPos(x + 1, y + 1);
	} else if (dir == "sw") {
		p.setPos(x - 1, y + 1);
	}
	return p;
}
*/

bool Object::playerWithinRange(Position *playerPos) {
    string dir[8] = {"ea", "we", "no", "so", "ne", "nw", "se", "sw"};
    for (int i = 0; i < 8; ++i) {
        if (getPos()->newPos(dir[i]) == *playerPos) { return true; }
    }
    return false;
}

string Object::getType() const {
	return this->type;
}

Object::~Object() {}
