export module atkEffect;
import <string>;
import statusEffect;
import player;

export class AtkEffect: public StatusEffect {    
    public:
        AtkEffect(bool isN, StatusEffect *p = nullptr, int d = 1, int s = 5); // by default, duration is 1 round and strength is 5
        int getEffect(std::string& type) const override;
};