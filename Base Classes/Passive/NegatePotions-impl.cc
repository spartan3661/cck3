module negatePotion;
import passive;
import livingEntity;
import statusEffect;

NegatePotions::NegatePotions(): Passive{"negatePotions"} {};

void NegatePotions::passiveEffect() {}

void NegatePotions::passiveEffect(StatusEffect* e){
    if (e->isNegative()){
        e->setNegative(false);
    }
}