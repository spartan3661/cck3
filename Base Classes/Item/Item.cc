export module item;
import <string>;
import entity;
import livingEntity;
import currency;
import position;
//import board;

export class Item: public Entity {
    std::string name;
    bool pickupable;
    Currency price;
    public:
        Item(Position pos, std::string name, bool pickupable = true, Currency price = Currency(0, 0));
        std::string getName() const;
        Currency getPrice() const;
        bool canPickup() const;
        void pickupItem(LivingEntity& to, bool useOnPickup); // params: Player *plr, Board& b
        virtual void useItem();
        virtual ~Item() = 0;
};