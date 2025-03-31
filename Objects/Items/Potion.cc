export module potion;
import <string>;
import item;
import currency;
import statusEffect;
import livingEntity;
import player;
import position;

export class Potion : public Item {
    private:
        StatusEffect *effect;
    public:
        Potion(Position pos, std::string name, Currency price, StatusEffect *effect);
        void pickupItem(LivingEntity& to);
        void useItem() override;
        void useItem(Player& plr, bool withCharge = false); // applies effect to player but not added to inventory

};