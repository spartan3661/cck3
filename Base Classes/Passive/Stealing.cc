export module stealing;
import <string>;
import passive;
import livingEntity;


export class Stealing: public Passive{
    int amount;
    public:
        Stealing(std::string type, int amount);
        void passiveEffect() override;
        void passiveEffect(LivingEntity& to, LivingEntity& from);
};