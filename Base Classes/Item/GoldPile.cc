export module goldPile;
import item;
import currency;
import <string>;
using namespace std;

export class GoldPile : public Item {
    private:
        int value;
    public:
        GoldPile(string name, int value);               
        void useItem(Player *plr) override;
        

}