export module multiply;
import passive;
import livingEntity;

class Multiply : public Passive{
    float multiplier;
    public:
        //void Multiply();
        void passiveEffect() override;
        void passiveEffect(LivingEntity& to);
};