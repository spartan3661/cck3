export module potion;
import <string>;
import item;
import statusEffect;
import player;

export class Potion : public Item {
    private:
        int strength;
        StatusEffect *effect;
    public:
        Potion(std::string name, int strength, StatusEffect *effect);
        void useItem() override;
        void useItem(Player& plr); // applies effect to player but not added to inventory

};