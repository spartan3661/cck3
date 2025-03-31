module item;
import <string>;
import livingEntity;
//import board;

using namespace std;

Item::Item(string name, bool pickupable): name{name}, pickupable{pickupable} {}

string Item::getName() const { return name; }

bool Item::canPickup() const { return pickupable; }

void Item::pickupItem(LivingEntity& to, bool useOnPickup) {
    if (!pickupable) return;

    //DYNAMIC CAST THIS PLEASE!!!!
    //plr.inventory.emplace_back(this);

    /*
    for (auto item in b.items) {
        if (item == this) {
            auto index = find(b.items.begin(), b.items.end(), item);
            b.items.erase(index);
        }
    }*/
}

void Item::useItem() {}

Item::~Item() {}