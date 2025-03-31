module goldPile;
import <string>;
import item;
import player;
import position;
import currency;

using namespace std;


GoldPile::GoldPile(Position pos, string name, Currency value): Item{pos, name}, value{value} {}

void GoldPile::useItem() {};  

void GoldPile::useItem(Player& plr) {
    plr.addMoney(value);
}
