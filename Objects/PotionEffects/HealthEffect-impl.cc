module healthEffect;
import <string>;
import <iostream>;
import statusEffect;

using namespace std;

HealthEffect::HealthEffect(bool isN, StatusEffect *p, int d, int s): StatusEffect{isN, p, d, s} {}

int HealthEffect::getEffect(string& type) const {
    int hp = 0;
    if (type == "hp") { hp = (negative ? -strength : strength); }
    
    if (p) { hp += p->getEffect(type); }
    return hp;
}

// OLD CODE
/*
void HealthPot::applyEffect(Player& plr) {
    if (!applied) {
        plr.hp += (negative ? -strength : strength);
        if (plr.getHp() > plr.getMaxHp()) { plr.hp = plr.getMaxHp(); }
        if (plr.getHp() < 0) { plr.hp = 0 }
    }

    if (dynamic_cast<StatusEffect*>(p)) {
        return p->applyEffect();
    }
}


void HealthEffect::removeEffect(Affected *prev) {

    // keep track of next and current effect positions
    Affected *next = p;
    Affected *cur = this;

    // commented this out just to be safe, since in this version of the game, health pots are always permanent
    
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