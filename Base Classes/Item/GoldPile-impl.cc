module goldPile;

using namespace std;

GoldPile::GoldPile(string name, int value) :Item{name}, value{value} {}

void GoldPile::useItem(Player *plr) override {
    plr.money += Currency{value, 0};
}

