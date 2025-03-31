module atkEffect;

using namespace std;

AtkEffect::AtkEffect(bool isN, StatusEffect *p, int d, int s): StatusEffect{isN, p, d, s} {}

int AtkEffect::getEffect(string& type) const {
    int atk = 0;
    if (type == "atk") { atk = (negative ? -strength : strength); }

    if (p) { atk += p->getEffect(type); }
    return atk;
}

//OLD CODE
/*
void AtkPot::applyEffect(Player& plr) {
    if (!applied) {
        applied = true;
        plr.atk += (negative ? -strength : strength);
    }

    if (dynamic_cast<StatusEffect*>(p)) {
        return p->applyEffect();
    }
}

void AtkEffect::removeEffect(Affected *prev) {
    // keep track of next and current effect positions
    Affected *next = p;
    Affected *cur = this;

    if (duration == 0) {
        // remove the effect
        plr.atk -= (negative ? -strength : strength);

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