export module barrierSuit;
import <string>;
import item;
import livingEntity;
import player;
import position;

export class BarrierSuit : public Item {
    public:
        BarrierSuit(Position pos, std::string name);
        void pickupItem(LivingEntity& to) override;
        ~BarrierSuit() override;
};