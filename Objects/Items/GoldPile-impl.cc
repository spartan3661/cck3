module goldPile;
import <iostream>;
import <string>;
import item;
import livingEntity;
import player;
import position;
import currency;
import position;

using namespace std;


GoldPile::GoldPile(Position pos, string name, Currency value): Item{pos, name}, value{value} {}

void GoldPile::pickupItem(LivingEntity& to) {
    if (!pickupable) return;

    try {
        Player& plr = dynamic_cast<Player&>(to); 

        useItem(plr);

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

void GoldPile::useItem() {};
void GoldPile::useItem(Player& plr) {
    plr.addMoney(value);
}