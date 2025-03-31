export module healthEffect;
import <string>;
import statusEffect;

export class HealthEffect: public StatusEffect {
    public:
        HealthEffect(bool isN, StatusEffect *p = nullptr, int d = -1, int s = 10); // by default, duration is permanent (-1) and strength is 10
        int getEffect(std::string& type) const override;
};