module item;
import <string>;
//import player;
//import board;

using namespace std;

string Item::getName() const { return name; }

bool Item::canPickup() const { return canPickup; }

void Item::pickupItem(Player& plr, Board& b, bool useOnPickup) {
    if (!canPickup) return;

    plr.inventory.emplace_back(this);

    for (auto item in b.items) {
        if (item == this) {
            auto index = find(b.items.begin(), b.items.end(), item);
            b.items.erase(index);
        }
    }
}

void Item::useItem() {}

Item::~Item() {}