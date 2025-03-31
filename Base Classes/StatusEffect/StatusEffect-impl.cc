module statusEffect;
import <memory>;
import <string>;

using namespace std;

StatusEffect::StatusEffect(bool isN, StatusEffect *p, int d, int s): negative{isN}, p{p}, duration{d}, strength{s} {}

// decrement the duration of all StatusEffects in the decorator list
void StatusEffect::decrementDuration() {
    // decrement if not zero (if negative, assumed to be permanent effect)
    if (duration > 0) { duration -= 1; }
    if (p) { return p->decrementDuration(); }
}


// getters

bool StatusEffect::isNegative() const { return negative; }

StatusEffect* StatusEffect::getNext() const { return p; }

int StatusEffect::getDuration() const { return duration; }

void StatusEffect::setNegative(bool val) { negative = val; }


// setter

void StatusEffect::setNext(StatusEffect *new_p) {
    p = new_p;
}