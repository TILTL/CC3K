#include "display.h"

using namespace std;
//如果是invalid input  action = “”
//每次打印完action 初始化action = “”

void Display::printPCInfo() {
    cout << "Please choose your race:" << endl;
    cout << "(s) for Shade  (125 HP, 25 Atk, 25 Def)" << endl;
    cout << "(d) for Drow (150 HP, 25 Atk , 15 Def, all potions have their effect magnified by 1.5)" << endl;
    cout << "(v) for Vampire (50 HP, 25 Atk, 25 Def, gains 5 HP every successful attack and has no maximum HP)" << endl;
    cout << "(t) for Troll (120 HP, 25 Atk, 15 Def, regains 5 HP every turn; HP is capped at 120 HP)" << endl;
    cout << "(g) for Goblin (110 HP, 15 Atk, 20 Def, steals 5 gold from every slain enemy)" << endl;
}

void Display::printMap(Floor *floor) const {
    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 79; j++) {
            char cell = floor->map[i][j];
            if ((cell >= '0') && (cell < '6')) {
                cout << "P";
            } else if ((cell >= '6') && (cell <= '9')) {
                cout << "G";
            } else {
                cout << cell;
            }
        }
        cout << endl;
    }
}

void Display::printPanel(Floor *floor) {
    Player *p = floor->getPlayer();
    cout << "Race: " << p->getType();
    cout << " Gold: " << p->getGold();
    cout << "                                                   ";
    cout << "Floor " << to_string(floor->level) << endl;
    cout << "HP: " << p->getHp() << endl;
    cout << "Atk: " << p->getAtk() << endl;
    cout << "Def: " << p->getDef() << endl;
    cout << "Action: " << action << endl;
}

void Display::printLose() {
    cout << "Loose!" << endl;
}
void Display::printWin() {
    cout << "Win!" << endl;
}

string Display::getAction() const {
    return action;
}

void Display::setAction(string ac) {
    action = ac;
}
