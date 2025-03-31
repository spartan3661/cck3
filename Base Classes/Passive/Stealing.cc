export module stealing;
import passive;
import livingEntity;


class Stealing : public Passive{
    int amount;
    public:
        void Stealing(int amount);
        void passiveEffect() override;
        void passiveEffect(LivingEntity& to, LivingEntity& from);
};