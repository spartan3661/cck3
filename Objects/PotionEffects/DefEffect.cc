export module defEffect;
import <string>;
import statusEffect;

export class DefEffect: public StatusEffect {    
    public:
        DefEffect(bool isN, StatusEffect *p = nullptr, int d = 1, int s = 5); // by default, duration is 1 round and strength is 5
        int getEffect(std::string& type) const override;
};