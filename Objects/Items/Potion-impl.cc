module potion;
import <iostream>;
import <string>;
import <memory>;
import livingEntity;
import player;
import currency;
import statusEffect;
import position;
using namespace std;

Potion::Potion(Position pos, string name, Currency price, StatusEffect *effect): Item{pos, name, true, price}, effect{effect} {}

void Potion::useItem() {};

void Potion::pickupItem(LivingEntity& to) {
    if (!pickupable) return;

    try {
        Player& plr = dynamic_cast<Player&>(to); 

        // plr.inventory.emplace_back(this);

        useItem(plr, false);

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

void Potion::useItem(Player& plr, bool withCharge) {
    plr.addEffect(effect);

    if (withCharge) {
        plr.subMoney(this->getPrice());
    }
};