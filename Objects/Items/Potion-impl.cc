module potion;
import <string>;
import player;
import statusEffect;
import position;
using namespace std;

Potion::Potion(Position pos, string name, int strength, StatusEffect *effect): Item{pos, name}, strength{strength}, effect{effect} {}

void Potion::useItem() {};

void Potion::useItem(Player& plr) { plr.addEffect(effect); };