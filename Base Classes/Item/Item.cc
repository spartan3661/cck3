export module item;
import <string>;
import entity;
import position;
import livingEntity;
//import board;

export class Item : public Entity {
    std::string name;
    bool pickupable;
    public:
        Item(Position pos, std::string name, bool pickupable = true);
        std::string getName() const;
        bool canPickup() const;
        void pickupItem(LivingEntity& to, bool useOnPickup); // params: Player *plr, Board& b
        virtual void useItem();
        virtual ~Item() = 0;
};