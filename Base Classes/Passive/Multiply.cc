export module multiply;
import <string>;
import passive;
import livingEntity;
import currency;

export class Multiply : public Passive{
    float multiplier;
    public:
        Multiply(std::string type, float multiplier);
        void passiveEffect() override;
        void passiveEffect(LivingEntity& to, Currency pickup);
};