export module compass;
import item;
import livingEntity;
import player;
import position;
import <string>;

export class Compass : public Item {

    public:
        Compass(Position pos, std::string name);
        void pickupItem(LivingEntity& to) override;   
        ~Compass() override;
};