#include "itemfactory.h"
using namespace std;

// 0-RH,1-BA,2-BD,3-PH,4-WA,5-WD,6-normalgoldpile,7 - small hoard, 8 - merchant hoard, 9 - dragon hoard
unique_ptr<Item> ItemFactory::createItem(char &type, ItemType itemType, std::unique_ptr<Position> pos) {
    if (itemType == ItemType::Potion) {
            int typeIdx = rand() % 6;
            type = '0' + typeIdx;
            switch (typeIdx) {
                case 0: return std::make_unique<RH>(std::move(pos));
                case 1: return std::make_unique<BA>(std::move(pos));
                case 2: return std::make_unique<BD>(std::move(pos));
                case 3: return std::make_unique<PH>(std::move(pos));
                case 4: return std::make_unique<WA>(std::move(pos));
                case 5: return std::make_unique<WD>(std::move(pos));
            }
    } else if (itemType == ItemType::Treasure) {
        int typeIdx = rand() % 8;
           if (typeIdx < 5) {
            type = '6';
            return std::make_unique<Normal>(std::move(pos));
        } else if (typeIdx < 7) {
            type = '7';
            return std::make_unique<Small>(std::move(pos));
        } else {
            type = '9';
            return std::make_unique<DHoard>(std::move(pos));
        }
    }
}

// 0-RH,1-BA,2-BD,3-PH,4-WA,5-WD,6-normalgoldpile,7 - small hoard, 8 - merchant hoard, 9 - dragon hoard
/*char ItemFactory::itemTypes[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

unique_ptr<Potion> ItemFactory::createPotion(char &type, unique_ptr<Position> pos) {
        int typeIdx = rand() % 6;
        type = itemTypes[typeIdx];
        if (typeIdx == 0) {
            return make_unique<RH>(move(pos));
        } else if (typeIdx == 1) {
            return make_unique<BA>(move(pos));
        } else if (typeIdx == 2) {
            return make_unique<BD>(move(pos));
        } else if (typeIdx == 3) {
            return make_unique<PH>(move(pos));
        } else if (typeIdx == 4) {
            return make_unique<WA>(move(pos));
        } else { 
            return make_unique<WD>(move(pos));
        }
}

unique_ptr<Treasure> ItemFactory::createTreasure(char &type, unique_ptr<Position> pos) {
    int typeIdx = rand() % 8;
    if (typeIdx < 5) {
        type = itemTypes[6];
        return make_unique<Normal>(move(pos));
    } else if (typeIdx < 7) {
        type = itemTypes[7];
        return make_unique<Small>(move(pos));
    } else {
        type = itemTypes[9];
        return make_unique<DHoard>(move(pos));
    }
}
*/
unique_ptr<Potion> ItemFactory::createPotion(int price, int i) {
        if (i == 0) {
            return make_unique<RH>(price);
        } else if (i == 1) {
            return make_unique<BA>(price);
        } else if (i == 2) {
            return make_unique<BD>(price);
        } else if (i == 3) {
            return make_unique<PH>(price);
        } else if (i == 4) {
            return make_unique<WA>(price);
        } else { 
            return make_unique<WD>(price);
        }
}


