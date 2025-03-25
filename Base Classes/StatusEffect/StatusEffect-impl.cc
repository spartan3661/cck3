module statusEffect;
import affected;

using namespace std;


StatusEffect::StatusEffect(Affected p, int d, int s, bool isN): p{p}, duration{d}, strength{s}, isNegative{isN} {}

void StatusEffect::applyEffect() {}

void StatusEffect::removeEffect() {}

void StatusEffect::decrementDuration() {}

bool StatusEffect::isNegative() { return isNegative }