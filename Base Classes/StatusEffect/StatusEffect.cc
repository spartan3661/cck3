export module statusEffect;
import <string>;

export class StatusEffect {

    protected:
        bool negative;
        StatusEffect *p;
        int duration, strength;
    
    public:
        StatusEffect(bool isN, StatusEffect *p, int d, int s);
        void decrementDuration();

        // getters
        virtual int getEffect(std::string& type) const = 0;
        bool isNegative() const;
        StatusEffect* getNext() const;
        int getDuration() const;
        
        // setter
        void setNext(StatusEffect *new_p);
        void setNegative(bool val);
};