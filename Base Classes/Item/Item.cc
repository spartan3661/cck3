export module item;
import <string>;
//import player;
//import board;

export class Item {
    string name;
    bool canPickup;
    public:
        std::string getName() const;
        bool canPickup() const;
        void pickupItem(); // params: Player *plr, Board& b
        virtual void useItem();
        virtual ~Item() = 0;
};