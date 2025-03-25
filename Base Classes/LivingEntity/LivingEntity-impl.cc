module livingEntity;
import <vector>;
import entity;
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
    Entity{pos}, race{race}, hp{hp}, atk{atk}, def{def}
{
    money = Currency{0, 0};
    passive = nullptr;
}

int LivingEntity::getHp() const { return hp; }

int LivingEntity::getAtk() const { return atk; }

int LivingEntity::getDef() const { return def; }

Currency LivingEntity::getMoney() const { return money; }

void LivingEntity::move(Position displacement) {
    coords += displacement;
    coords.changeDir(displacement.dir);
}

void LivingEntity::attack() {}