#include "gameController.h"

using namespace std;

void GameController::start() {
    // print starting information
    // choose race
    char race;
    display->printPCInfo();
    while (1) {
        cin >> race;
        if(race == 's' || race == 'd' || race == 'v' || race == 'g' || race == 't') {
            break;
        } else {
            cout << "Invalide race, choose again!" << endl;
        }
    }
    display->printMap(floor);
    floor->initFloor(race);
    display->printPanel(floor);

    // laying out the map, spawn all elements in order
    display->setAction("Player character has spawned.");
    display->printMap(floor);
    display->printPanel(floor);


    // input
    string input;
    while(cin >> input) {
        display->setAction("");

        //检查enemy周围有没有player
        // 整理所有的message（PC攻击敌人+敌人攻击PC），然后更新到action里面
       
        readCommand(input);
        if (this->status == "restart" || this->status == "quit") {
            break;
        }
        if (!this->getFloor()->getIsFrozen()) {
             floor->autoAttackPlayer();
             floor->randomMove();
        }
        if (floor->getPlayer()->getHp() <= 0) {
            cout << "You died!" << endl;
            status = "die";
            break;
        }
        if (this->getFloor()->level == 6) {
            this->status == "win";
            break;
        }
        display->printMap(floor);
        display->printPanel(floor);
    }
}

void GameController::readCommand(string input) {
    //no,so,ea,we,ne,nw,se,sw -> move player
    //u direction -> take potion
    //a direction -> attack enemy
    //f -> stop enemy moving
    //r -> restart, initDisplay, initFloor, select race

    if (validDirection(input)) { //player moves
        //cout << input << endl;
        cout << floor->sb();
        //display->setAction(floor->movePlayer(input));
    } else if (input == "u") { // uses the potion indicated by the direction (e.g. no, so, ea).
        string dir;
        cin >> dir;
        if (validDirection(dir)) {
            string potionType = floor->usePotion(dir);
            if (potionType != "") {
                display->setAction("Player PC uses" + potionType + ".");
            } else {
                display->setAction("No valid potion.");
            }
        } else {
            display->setAction("Invalid direction.");
        }

    } else if (input == "a") { //attack player indicated by direction
        string dir;
        cin >> dir;
        if (validDirection(dir)) {
            display->setAction(floor->attackDir(dir));
        } else {
            display->setAction("Invalid direction.");
        }

    } else if (input == "f") {
        this->getFloor()->frozenEnemy();
        
    } else if (input == "r") {
        this->status = "restart";

    } else if (input == "q") {
        this->status = "quit";

    } else {
        //invalid input
        display->setAction("Invalid input, please try again.");
        return;
    }
    string msg = display->getAction();
    display->setAction(msg + floor->autoAttackPlayer());
    // buff
    // troll
    if (floor->getPlayer()->getType() == "troll") {
        floor->regainFive();
    }
}

bool GameController::validDirection(string input) const {
    return ((input == "no") || (input == "so") || (input == "ea") || (input == "we") || (input == "ne") || (input == "nw") || (input == "se") || (input == "sw"));
}

Floor *GameController::getFloor() const{
    return floor;
}

string GameController::getStatus() const {
    return status;
}

Display *GameController::getDisplay() const {
    return display;
}
