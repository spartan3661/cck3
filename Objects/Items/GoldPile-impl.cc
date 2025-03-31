module goldPile;
import <string>;
import item;
import player;
import currency;

using namespace std;


GoldPile::GoldPile(string name, Currency value): Item{name}, value{value} {}

void GoldPile::useItem() {};  

void GoldPile::useItem(Player& plr) {
    plr.addMoney(value);
}
