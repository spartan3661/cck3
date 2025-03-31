module healthStealing;
import passive;
import livingEntity;

HealthRegen::HealthRegen(int rate) : rate{rate}{}
void HealthRegen::passiveEffect() override {}
void HealthRegen::passiveEffect(LivingEntity& to) {
    if (to.health += rate > to.maxHp){
        to.health = to.maxHp;
    } else{
        to.health += rate;
    }
}