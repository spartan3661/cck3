export module goldPile;
import <string>;
import item;
import player;
import currency;
import position;

export class GoldPile : public Item {
    Currency value;
    public:
        GoldPile(Position pos, std::string name, Currency value);        
        void useItem() override;       
        void useItem(Player& plr);
};