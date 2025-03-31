module potion;
import <string>;
import player;
import statusEffect;

using namespace std;

Potion::Potion(string name, int strength, StatusEffect *effect): Item{name}, strength{strength}, effect{effect} {}

void Potion::useItem() {};

void Potion::useItem(Player& plr) { plr.addEffect(effect); };