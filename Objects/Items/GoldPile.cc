export module goldPile;
import <string>;
import item;
import player;
import currency;


export class GoldPile : public Item {
    Currency value;
    public:
        GoldPile(std::string name, Currency value);        
        void useItem() override;       
        void useItem(Player& plr);
};