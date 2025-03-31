export module healthRegen;
import passive;
import livingEntity;

class HealthRegen : public Passive{
    int rate;
    public:
        void HealthRegen(int rate);
        void passiveEffect() override;
        void passiveEffect(LivingEntity& to);
};