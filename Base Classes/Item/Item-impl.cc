module item;
import <iostream>;
import <string>;
import <memory>;
import entity;
import livingEntity;
import currency;
import position;
//import board;

using namespace std;

Item::Item(Position pos, string name, bool pickupable, Currency price): Entity{pos}, name{name}, pickupable{pickupable}, price{price} {}

string Item::getName() const { return name; }

Currency Item::getPrice() const { return price; }

bool Item::canPickup() const { return pickupable; }

void Item::pickupItem(LivingEntity& to, bool useOnPickup) {
    if (!pickupable) return;

    //DYNAMIC CAST THIS PLEASE!!!!
    try {
        //Player& plr = dynamic_cast<Player&>(to); 

        //plr.inventory.emplace_back(this);

        //if (useOnPickup) { useItem(); };

        /*
        for (auto item in b.items) {
            if (item == this) {
                auto index = find(b.items.begin(), b.items.end(), item);
                b.items.erase(index);
        }
        }*/
        
    } catch(bad_cast &e) {
        cerr << e.what() << endl;
    }
    //plr.inventory.emplace_back(this);
}

void Item::useItem() {}

Item::~Item() {}