#include "merchant.h"

using namespace std;

Merchant::Merchant(unique_ptr<Position> pos) {
    this->type = "Merchant";
    this->hp = 30;
    this->atk = 70;
    this->def = 5;
    this->pos = std::move(pos);
    this->isNeutral = true;

    for (int i = 0; i < 6; ++i) {
        int price = rand() % 5 + 1;
        int num = rand() % 5 + 1;
        store[ItemFactory::createPotion(price, i)] = num;
    }
}

void Merchant::sell(string p, Player &player) {
    double magnify = 1.0;
    if (player.getType() == "Drow") {
        magnify = 1.5;
    }
    for (map<unique_ptr<Potion>, int>::iterator it = store.begin(); it != store.end(); ++it) {
        if (p == it->first.get()->getType()) {
            int price = it->first.get()->getPrice();
            if (player.getGold() < price) {
                cout << "Not sufficient gold! Choose another potion or exit." << endl;
            } else if (it->second > 0) {
                it->first.get()->affectPlayer(player, magnify);
                player.spendGold(price);
                it->second -= 1;
                if (it->second == 0) {
                    store.erase(it);
                }
                cout << "You bought a " << p << endl;
                printData(player);
            }
            break;
        }
    }
}

void Merchant::printStore() const {
    cout << endl;
    cout << "---------store---------" << endl;
    for (map<unique_ptr<Potion>, int>::const_iterator it = store.begin(); it != store.end(); ++it) {
        cout << "    ";
        if (it->first.get() != nullptr) {
            cout << it->first.get()->getType() << " : $" << it->first.get()->getPrice() << " X " << it->second;
        } else {
            cout << "empty";
        }
        cout << "    " << endl;
    }
    cout << "-----------------------" << endl;
    cout << endl;
    cout << "(exit) to leave the store." << endl;
}

void Merchant::printData(Player &p) const {
    cout << endl;
    cout << "Race: " << p.getType();
    cout << " Gold: " << p.getGold() << endl;
    cout << "HP: " << p.getHp() << endl;
    cout << "Atk: " << p.getAtk() << endl;
    cout << "Def: " << p.getDef() << endl;
}

void Merchant::printFunction() const {
    cout << "(RH) for Restore health: restore up to 10 HP (cannot exceed maximum prescribed by race)" << endl;
    cout << "(BA) for Boost Atk: increase ATK by 5" << endl;
    cout << "(BD) for Boost Def: increase Def by 5" << endl;
    cout << "(PH) for Poison health: lose up to 10 HP (cannot fall below 0 HP)" << endl;
    cout << "(WA) for Wound Atk: decrease Atk by 5" << endl;
    cout << "(WD) for Wound Def: decrease Def by 5" << endl;
    cout << "Please choose a potion listed above and pay." << endl;
}
