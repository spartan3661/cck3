export module potion;
import item;
import statusEffect;
import passive;
import <string>;
using namespace std;

export class Potion : public Item {
    private:
        StatusEffect *effect;
    public:
        Potion(string name, int strength, StatusEffect effect);               
        void pickupItem(Player *plr, Board& b) override ;
        void useItem(Player *plr) override;      // applies effect to player but not added to inventory
        friend class Passive;

}