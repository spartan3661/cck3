module barrierSuit;
import <iostream>;
import <string>;
import livingEntity;
import player;
import position;
import item;

using namespace std;

BarrierSuit::BarrierSuit(Position pos, string name) : Item{pos, name, false} {}

void BarrierSuit::pickupItem(LivingEntity& to) {
    if (!pickupable) return;

    try {
        Player& plr = dynamic_cast<Player&>(to); 

        plr.equipArmour(this);

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
}

BarrierSuit::~BarrierSuit() {}