module merchant;
import <vector>;
import <string>;
import <cmath>;
import <iostream>;
import <memory>;
import livingEntity;
import enemy;
import player;
import position;
import currency;
import statusEffect;
import healthEffect;
import atkEffect;
import defEffect;
import item;
import potion;

using namespace std;

Merchant::Merchant(Position pos):
    Enemy{pos, Race::MERCHANT, 30, 70, 5, nullptr, false, false}
{
    shop_items = {
        new Potion{Position{0, 0}, "Restore health (RH)", Currency{10, 0}, new HealthEffect{false}},
        new Potion{Position{0, 0}, "Boost atk (BA)", Currency{7, 0}, new AtkEffect{false}},
        new Potion{Position{0, 0}, "Boost def (BD)", Currency{5, 0}, new DefEffect{false}}
    };

    stock = {1, 2, 2};
}

void Merchant::onDeath() {}
void Merchant::notify(Subject& whoNotified, std::string action) {
    try {
        LivingEntity& entity = dynamic_cast<LivingEntity&>(whoNotified);

        if (action == "attack") {
            isHostile = true;
            int dmg = ceil(100.0f/(100 + def) * entity.getAtk());
            // if dragonsuit, dmg = ceil(dmg/2);
            hp -= dmg;
            if (hp <= 0) {
                hp = 0;
                onDeath();
            }
        }

    } catch(bad_cast &e) {
        cerr << e.what() << endl;
    }
}

void Merchant::printShop() {
    cout << "Shop:" << endl;
    size_t size = shop_items.size();
    for (size_t i = 0; i < size; i++) {
        cout << "[ " << i << " ]: " << shop_items[i]->getName() << " - " << shop_items[i]->getPrice() << endl;
    }
}

void Merchant::purchase(Player& plr, int shop_index) {
    try{
        Item *item = shop_items.at(shop_index);
        Potion *item_sold = dynamic_cast<Potion*>(item);

        if (plr.getMoney() < item_sold->getPrice()) {
            cout << "Not enough funds." << endl;
            return;
        }

        if (stock[shop_index] > 0) {
            item_sold->useItem(plr, true);
            money += item_sold->getPrice();
            stock[shop_index] -= 1;
        } else {
            cout << "Out of stock." << endl;
        }
    } catch (const std::out_of_range& e) {
        cerr << "Caught exception: " << e.what() << endl;
        cout << "Not a valid item!" << endl;
    }
}