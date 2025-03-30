module potion;

using namespace std;

Potion::Potion(string name, StatusEffect effect) : Item{name}, effect{effect} {

}



void Potion::useItem(Player &plr) override {
    plr.effects = new StatusEffect{plr, effects};
    plr.knownPotions.emplace_back(effects);
}
