module healthRegen;
import <string>;
import passive;
import livingEntity;

HealthRegen::HealthRegen(int rate): Passive{"regen"}, rate{rate}{}

void HealthRegen::passiveEffect() {}

void HealthRegen::passiveEffect(LivingEntity& to) {
    to.addHp(rate);
}