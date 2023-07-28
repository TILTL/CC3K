#include "floor.h"
#include <iostream>
using namespace std;

Floor::Floor() {
    this->player = new Player();
    for (int i = 0; i < 6; ++i){
        this->isPotionKnown[i] = false;
    }
}

void Floor::initMap(string file) {
    ifstream in{file};
	string str;
	for (int i = 0; i < 25; i++) {
		getline(in, str);
		for (int j = 0; j < 79; j++) {
			map[i][j] = str[j];
            defaultMap[i][j] = str[j];
		}
	}
}

void Floor::redrawMap() {
    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 79; j++) {
            map[i][j] = defaultMap[i][j];
        }
    }
}

// destructor
Floor::~Floor() {
    // delete enemy
    for (int i = 0; i < enemies.size(); ++i) {
        Enemy * tmp = enemies[i];
        enemies.erase(enemies.begin() + i);
        delete tmp;
        --i;
    }
    // delete treasure
    for (int i = 0; i < treasures.size(); ++i) { 
        Treasure *tmp = treasures[i];
        treasures.erase(treasures.begin() + i);
        delete tmp;
        --i;
    }
    // delete potion
    for (int i = 0; i < potions.size(); ++i) {
        Potion * tmp = potions[i];
        potions.erase(potions.begin() + i);
        delete tmp;
        --i;
    }
    // delete chamber
    for (int i = 0; i < chambers.size(); ++i) {
        Chamber * tmp = chambers[i];
        chambers.erase(chambers.begin() + i);
        delete tmp;
        --i;
    }
    // delete player
    delete player;
}

void Floor::initFloor(char race) {
    int playerChamberID;
    int dragonNum = 0;
    generateChamber();
    spawnPlayer(race, playerChamberID);
    spawnStair(playerChamberID);
    spawnItems(dragonNum);
    spawnEnemies(dragonNum);
    
    /*for (int i = 0; i < 6; i++) {
        isPotionKnown[i] = false;
    }*/
}

void Floor::initNext() {
    redrawMap();
    int playerChamberID;
    int dragonNum = 0;
    generateChamber();
    playerChamberID = 1 + rand() % 5;
    Position pos = chambers[playerChamberID - 1]->getPosition();
    player->modifyAtk(player->getDefaultAtk());
    player->modifyDef(player->getDefaultDef());
    player->setPos(&pos);
    map[pos.getY()][pos.getX()] = '@';
    spawnStair(playerChamberID);
    spawnItems(dragonNum);
    spawnEnemies(dragonNum);
    /*for (int i = 0; i < 6; i++) {
        isPotionKnown[i] = false;
    }*/
}

// spawn chamber
void Floor::generateChamber() {
	for(int i = 0; i < 5; i++) {
		Chamber *c = new Chamber(i + 1);
		chambers.push_back(c);
	}
}

// spawn player
void Floor::spawnPlayer(char race, int &playerChamberID) {
    playerChamberID = rand() % 5 + 1;
    Position pos = chambers[playerChamberID - 1]->getPosition();
    player = PlayerFactory::createPlayer(race, &pos);
    map[pos.getY()][pos.getX()] = '@';
}

// spawn stair
void Floor::spawnStair(int &playerChamberID) {
    int stairChamberID = rand() % 4 + 1;
    if (stairChamberID < playerChamberID) {
        Position pos = chambers[stairChamberID - 1]->getPosition();
        map[pos.getY()][pos.getX()] = '/';
    } else {
        Position pos = chambers[stairChamberID]->getPosition();
        map[pos.getY()][pos.getX()] = '/';
    }
}

// spawn items
void Floor::spawnItems(int &dragonNum) {
    int chamberID;
    Position pos;
    char type;
    
    //spawn potions
    for (int i = 0; i < 10; i++) {
        chamberID = 1 + rand() % 5;
        pos = getValidPos(chamberID);
        potions.push_back(ItemFactory::createPotion(type, &pos));
        map[pos.getY()][pos.getX()] = type;
    }

    //spawn treasures
    for (int i = 0; i < 10; i++) {
        chamberID = 1 + rand() % 5;
        pos = getValidPos(chamberID);
        Treasure *t = ItemFactory::createTreasure(type, &pos);
        treasures.push_back(t);
        map[pos.getY()][pos.getX()] = type;
    
        if (type == '9') { //if the generated treasure is dragon hoard 
            DHoard *dh = static_cast <DHoard *>(t);
            Position dragonPos = generateDragonPos(&pos);
            enemies.push_back(new Dragon(&dragonPos, dh));
            map[dragonPos.getY()][dragonPos.getX()] = 'D';
            dragonNum++;
        }
    }
}

// spawn dragon
Position Floor::generateDragonPos(Position *dhPos) {
    Position pos;
	while (1) {
		int idx = rand() % 8;
		string dir[8] = {"ea", "we", "no", "so", "ne", "nw", "sw", "se"};
		pos = dhPos->newPos(dir[idx]);
        if ((map[pos.getY()][pos.getX()] == '.')) break;
	}
	return pos;
}

// spawn enemies
void Floor::spawnEnemies(int &dragonNum) {
    int num = 20 - dragonNum;
    int chamberID;
    Position pos;
    char type;
    for (int i = 0; i < num; i++) {
        chamberID = 1 + rand() % 5;
        pos = getValidPos(chamberID);
        enemies.push_back(EnemyFactory::createEnemy(type, &pos));
        map[pos.getY()][pos.getX()] = type;
    }
}

string Floor::usePotion(string dir) {
    //drow can modify potion by 1.5
    Position *curPos = player->getPos();
    Position newPos = curPos->newPos(dir);
    double magnify = 1.0;
    // drow's buff
    if (player->getType() == "drow") {
        magnify = 1.5;
    }
    char cell = map[newPos.getY()][newPos.getX()];
    if (cell == '0') {
        double newHP = player->getHp() + 10 * magnify;
        player->modifyHp(static_cast<int>(newHP));
        isPotionKnown[0] = true;
    } else if (cell == '1') {
        double newAtk = player->getAtk() + 5 * magnify;
        player->modifyAtk(static_cast<int>(newAtk));
        isPotionKnown[1] = true;
    } else if (cell == '2') {
        double newDef = player->getDef() + 5 * magnify;
        player->modifyDef(static_cast<int>(newDef));
        isPotionKnown[2] = true;
    } else if (cell == '3') {
        double newHP = player->getHp() - 10 * magnify;
        player->modifyHp(static_cast<int>(newHP));
        isPotionKnown[3] = true;
    } else if (cell == '4') {
        double newAtk = player->getAtk() - 5 * magnify;
        player->modifyAtk(static_cast<int>(newAtk));
        isPotionKnown[4] = true;
    } else if (cell == '5') {
        double newDef = player->getDef() - 5 * magnify;
        player->modifyDef(static_cast<int>(newDef));
        isPotionKnown[5] = true;
    } else {
        return "Potion not found";
    }
    for (int i = 0; i < potions.size(); i++) {
        if (*potions[i]->getPos() == newPos) {
            string type = potions[i]->getType();
            Potion *tmp = potions[i];
            potions.erase(potions.begin() + i);
            delete tmp;
            modifyMap(newPos, curPos);
            return type;
        }
    }
    return "";
} 


string Floor::attackDir(string dir) {
    Position *curPos = player->getPos();
    Position newPos = curPos->newPos(dir);
    char cell = map[newPos.getY()][newPos.getX()];
    if (cell == 'H' || cell == 'W' || cell == 'E' || cell == 'O' || cell == 'M' || cell == 'D' || cell == 'L') {
        string action;
        for (int i = 0; i < enemies.size(); i++) {
            if (enemies[i]->getPos() == &newPos) {
                action = player->attackEnemy(enemies[i]);
                if (enemies[i]->getHp() <= 0) { //If this enemy dies...
                    if (player->getType() == "goblin") { //if the PC is goblin, steal 5 golds
                        player->pickGold(5);
                    }
                    string enemyType = enemies[i]->getType();
                    if (enemyType == "dragon") {
                        //free the dragon hoard
                        Dragon *dragon = static_cast<Dragon *>(enemies[i]);
                        dragon->freeHoard();
                        map[newPos.getY()][newPos.getX()] = defaultMap[newPos.getY()][newPos.getX()];
                    } else if (enemyType == "merchant") {
                        //add a merchant hoard
                        //merchants become hostile
                        MHoard *mhoard = new MHoard(&newPos);
                        treasures.push_back(mhoard);
                        map[newPos.getY()][newPos.getX()] = '8';
                        if (enemies[i]->getIsNeutral()) {
                            for (int k = 0; k < enemies.size(); k++) {
                                if (enemies[k]->getType() == "merchant") {
                                    enemies[k]->notNeutral();
                                }
                            }
                        }
                    } else if (enemyType == "human") {
                        //add two normal
                        Normal *hHoard = new Normal(&newPos, 4);
                        treasures.push_back(hHoard);
                        map[newPos.getY()][newPos.getX()] = '6';
                    } else {
                        int random = rand() % 2;
                        if (random == 0) {
                            player->pickGold(1);
                        } else {
                            player->pickGold(2);
                        }
                        map[newPos.getY()][newPos.getX()] = defaultMap[newPos.getY()][newPos.getX()];
                        //drop either a small pile or normal pile of gold (discussed below). 
                        //This gold is immediately added to the player character’s total.
                    }
                    Enemy *tmp = enemies[i];
                    enemies.erase(enemies.begin() + i);
                    delete tmp;
                }
            }
        }
        if (player->getType() == "vampire" && cell == 'W')
        {
            player->modifyHp(player->getHp() - 5);
        } else if (player->getType() == "vampire" && cell != 'L') {
            regainFive();
        } else if (player->getType() == "vampire" && action != "You missed!") {
            regainFive();
        }
        return action;
    } else {
        return "Enemy not found.";
    }
}

void Floor::regainFive() {
    player->modifyHp(player->getHp() + 5);
}


string Floor::sb() {
    return "sb";
}


string Floor::movePlayer(string dir) {
    return "sb";
    string msg;
    
    /*Position *curPos = player->getPos();
    cout << "sb";
    Position newPos = player->getPos()->newPos(dir);
    char cell = map[newPos.getY()][newPos.getX()];
    cout << "here: " << cell << endl;
    
	if (cell == '6' || cell == '7') { //small or normal hoard
        msg = "PC moves " + dir;
        msg += pickGold(newPos);
        modifyMap(newPos, curPos);
    } else if (cell == '9') { //dragon hoard
        //find that dragon hoard
        for (int i = 0; i < treasures.size(); i++) {
            if (*treasures[i]->getPos() == newPos) {
                DHoard *dh = static_cast <DHoard *>(treasures[i]);
                msg = "PC moves " + dir;
                modifyMap(newPos, curPos);
                if (!dh->getIsGuard()) { //if this hoard is not guarded
                    msg += pickGold(newPos);
                } else { //dragon will attack player
                    msg += " and sees an guarded dragon hoard.";
                   
                } 
            }
        }
    
    } else if (cell == '/') {
        if (level != 6) {
            msg = "You enter Floor " + to_string(++level);
            initNext();
        }   
        msg = "You win!";
        
    } else if (cell == '.' || cell == '+' || cell == '#') {
        modifyMap(newPos, curPos);
        msg = "PC moves " + dir;
        for (int i = 0; i < potions.size(); i++) {
            if (potions[i]->playerWithinRange(&newPos)) {
                msg += seePotion(potions[i]);
            }
        } 

    } else {
        msg = "Invalid move.";
    }

    */
   //return msg;
}

string Floor::pickGold(Position p) {
    for (int i = 0; i < treasures.size(); i++) {
        if (*treasures[i]->getPos() == p) {
            Treasure *tmp = treasures[i];
            int amount = tmp->getValue();
            player->pickGold(amount);
            treasures.erase(treasures.begin() + i);
            delete tmp;
            return "and picked " + to_string(amount) + " golds.";
        }
    }
    return "";
}

void Floor::modifyMap(Position newPos, Position *curPos) {
    map[newPos.getY()][newPos.getX()] = '@';
    map[curPos->getY()][curPos->getX()] = defaultMap[curPos->getY()][curPos->getX()];
    player->setPos(&newPos);
}

string Floor::seePotion(Potion *p) {
    string msg;
    string type = p->getType();
    if(type == "RH"){
        if (isPotionKnown[0]){
            msg = "You see a Restore Health potion. ";
        }
   } else if (type == "BA"){
        if (isPotionKnown[1]){
        msg = "You see a Boost potion. ";
        }
   } else if (type == "BD"){
        if (isPotionKnown[2]){
        msg = "You see a Boost Defense potion. ";
        }    
   } else if (type == "PH"){
        if (isPotionKnown[3]){
        msg = "You see a Poison Health potion. ";
        }    
   } else if (type == "WA"){
        if (isPotionKnown[4]){
        msg = "You see a Wound Attack potion. ";
        }    
   } else if (type == "WD"){
        if (isPotionKnown[5]){
        msg = "You see a Wound Defense potion. ";
        }   
   } else {
        msg = "You see an unknown potion. ";   
   }
    return msg;
}

//random movement
void Floor::randomMove() {
    //按照pos顺序放到vector里
    sortEnemies();
    //遍历vector， 判断每个enemy周围有没有player，如果有就不move
    for (int i = 0; i < enemies.size(); i++) {
        if(enemies[i]->getType() == "dragon") {
            continue;
        }
        if (!enemies[i]->playerWithinRange(player->getPos())) {
            while (1) {
                Position newPos = enemies[i]->move();
                char c = map[newPos.getY()][newPos.getX()];
                if (c == '.') {
                    enemies[i]->setPos(&newPos);
                    break;
                }
            }
        }
    }
}

void Floor::sortEnemies() {
    int i, j;
    Enemy *key;
    for (i = 1; i < enemies.size(); i++) {
        key = enemies[i];
        j = i - 1;
        while (j >= 0 && *key->getPos() < *enemies[j]->getPos()) {
            enemies[j + 1] = enemies[j];
            j = j - 1;
        }
        enemies[j + 1] = key;
    }
}

string Floor::autoAttackPlayer() {
    string autoAttackLog = "";
    //if player is near dragon hoards, change those dragons to hostile
    for (int i = 0; i < treasures.size(); i++) {
        if (treasures[i]->getType() == "dragon hoard") {
            DHoard *dh = static_cast <DHoard *>(treasures[i]);
            if (dh->playerWithinRange(player->getPos())) {
                 for (int i = 0; i < enemies.size(); i++) {
                        if (enemies[i]->getType() == "dragon") {
                            if (*static_cast <Dragon *>(enemies[i])->getDHoard()->getPos() == *dh->getPos()) {
                                Dragon *d = static_cast <Dragon *> (enemies[i]);
                                d->notNeutral();
                            }
                            
                        }
                    }
            }
        }
    }
    
    for (int i = 0; i < enemies.size(); i++) {
        if (enemies[i]->getType() == "dragon") {
            Dragon *d = static_cast <Dragon *>(enemies[i]);
            if (d->playerWithinRange(player->getPos())) d->notNeutral(); //if player is near any dragon, change dragon to hostile
            if (!d->getIsNeutral()) {
                autoAttackLog += d->attackPlayer(player);
                d->setNeutral();
                break;
            }
        }
        if (enemies[i]->playerWithinRange(player->getPos())) {
            if (!enemies[i]->getIsNeutral()) {
                autoAttackLog += enemies[i]->attackPlayer(player);
            }
            return autoAttackLog;
        }
    }
    return "";
}

Position Floor::getValidPos(int chamberID) {
    Position pos;
    while (1) {
        pos = chambers[chamberID - 1]->getPosition();
        if (map[pos.getY()][pos.getX()] == '.') {
            break;
        }
    }
    return pos;
}

Player *Floor::getPlayer() const{
    return player;
}

void Floor::frozenEnemy() {
    if(isFrozen) {
        isFrozen = false;
    } else {
        isFrozen = true;
    }
}

bool Floor::getIsFrozen() const{
    return isFrozen;
}
