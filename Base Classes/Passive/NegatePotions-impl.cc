module healthStealing;
import passive;
import livingEntity;
import potion;
import statisEffect;

//void NegatePotions();
void NegatePotions::passiveEffect() override{}
void NegatePotions::passiveEffect(Potion& potion){
    if (potion.effect->negative){
        potion.effect->negative = false;
    }
}