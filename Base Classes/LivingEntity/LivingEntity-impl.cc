module livingEntity;
import <vector>;
import entity;
import subject_observer;
import currency;
import position;

using namespace std;

LivingEntity::LivingEntity(
    Position pos,
    Race race,
    int hp,
    int atk,
    int def
): 
    Entity{pos}, race{race}, maxhp{hp}, hp{hp}, atk{atk}, def{def}, money{0, 0}
{
    passive = nullptr;
}

int LivingEntity::getMaxHp() const { return maxhp; }

int LivingEntity::getHp() const { return hp; }

int LivingEntity::getAtk() const { return atk; }

int LivingEntity::getDef() const { return def; }

Currency LivingEntity::getMoney() const { return money; }

Race LivingEntity::getRace(){
    return race;
}

void LivingEntity::addMoney(Currency amount) { money += amount; }

void LivingEntity::move(Position displacement) {
    coords += displacement;
    coords.changeDir(displacement.getDir());
}

void LivingEntity::attack() {}