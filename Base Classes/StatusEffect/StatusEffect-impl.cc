module statusEffect;
import affected;

using namespace std;


StatusEffect::StatusEffect(Affected *p, int d, int s, bool isN): p{p}, duration{d}, strength{s}, negative{isN} {}

void StatusEffect::applyEffect() {}

void StatusEffect::removeEffect() {}

void StatusEffect::decrementDuration() {}

bool StatusEffect::isNegative() const { return negative; }