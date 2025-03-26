export module item;
import <string>;
import livingEntity;
//import board;

export class Item {
    std::string name;
    bool pickupable;
    public:
        std::string getName() const;
        bool canPickup() const;
        void pickupItem(LivingEntity& to, bool useOnPickup); // params: Player *plr, Board& b
        virtual void useItem();
        virtual ~Item() = 0;
};