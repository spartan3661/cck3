export module negatePotion;
import <string>;
import passive;
import statusEffect;

export class NegatePotions : public Passive{
    public:
        NegatePotions();
        void passiveEffect() override;
        void passiveEffect(StatusEffect* e);
};