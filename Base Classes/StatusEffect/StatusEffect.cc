export module statusEffect;
import affected;

export class StatusEffect: public Affected {

    protected:
        Affected *p;

    private:
        int duration, strength;
        bool negative;
    
    public:
        StatusEffect(Affected *p, int d, int s, bool isN);
        virtual void applyEffect() = 0;
        virtual void removeEffect() = 0;
        void decrementDuration();
        bool isNegative() const;
};