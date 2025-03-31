export module goldPile;
import <string>;
import item;
import livingEntity;
import player;
import position;
import currency;
import position;

export class GoldPile : public Item {
    Currency value;
    public:
        GoldPile(Position pos,std::string name, Currency value);     
        void pickupItem(LivingEntity& to) override;
        void useItem() override;       
        void useItem(Player& plr);
};