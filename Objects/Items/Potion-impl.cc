module potion;
import <string>;
import player;
import currency;
import statusEffect;
import position;
using namespace std;

Potion::Potion(Position pos, string name, Currency price, StatusEffect *effect): Item{pos, name, true, price}, effect{effect} {}

void Potion::useItem() {};

void Potion::useItem(Player& plr, bool withCharge) {
    plr.addEffect(effect);

    if (withCharge) {
        plr.subMoney(this->getPrice());
    }
};