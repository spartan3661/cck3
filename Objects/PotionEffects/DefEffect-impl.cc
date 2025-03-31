module defEffect;
import <string>;
import statusEffect;

using namespace std;

DefEffect::DefEffect(bool isN, StatusEffect *p, int d, int s): StatusEffect{isN, p, d, s} {}

int DefEffect::getEffect(string& type) const {
    int def = 0;
    if (type == "def") { def = (negative ? -strength : strength); }

    if (p) { def += p->getEffect(type); }
    return def;
}

// OLD CODE
/*
void DefPot::applyEffect(Player& plr) {
    if (!applied) {
        applied = true;
        plr.def += (negative ? -strength : strength);
    }

    if (dynamic_cast<StatusEffect*>(p)) {
        return p->applyEffect();
    }
}

void DefEffect::removeEffect(Affected *prev) {
    // keep track of next and current effect positions
    Affected *next = p;
    Affected *cur = this;

    if (duration == 0) {
        // remove the effect
        plr.def -= (negative ? -strength : strength);

        if (prev) {
            // link previous and next status effect
            cur = prev;
            prev->p = p;
            p = nullptr;
        }
    }

    StatusEffect* nextEffect = dynamic_cast<StatusEffect*>(next);
    if (nextEffect) { // if next affected pointer is the player, stop
        return next->decrementDuration();
    }
}
    */