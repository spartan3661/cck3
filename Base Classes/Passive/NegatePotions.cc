export module negatePotion;
import passive;
import livingEntity;
import statusEffect;

class NegatePotions : public Passive{
    public:
        //void NegatePotions();
        void passiveEffect() override;
        void passiveEffect(LivingEntity& to);
};