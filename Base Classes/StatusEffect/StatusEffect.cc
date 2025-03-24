export module statusEffect;
import affected;

export class StatusEffect: public Affected {

    int duration, strength;
    bool isNegative;

    protected:
        Affected *p;
    
    public:
        StatusEffect(int d, int s, bool isN);
        virtual void applyEffect() = 0;
        virtual void removeEffect() = 0;
        void decrementDuration();
        bool isNegative() const;
};