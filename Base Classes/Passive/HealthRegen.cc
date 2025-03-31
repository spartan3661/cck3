export module healthRegen;
import passive;
import livingEntity;

export class HealthRegen: public Passive{
    int rate;
    public:
        HealthRegen(int rate);
        void passiveEffect() override;
        void passiveEffect(LivingEntity& to);
};