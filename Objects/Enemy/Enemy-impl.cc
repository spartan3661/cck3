module enemy;
import <vector>;
import <string>;
import <cmath>;
import <iostream>;
import <memory>;
import position;
import currency;
import livingEntity;
import passive;

using namespace std;

Enemy::Enemy(
    Position pos,
    Race race,
    int hp,
    int atk,
    int def,
    Passive *passive,
    bool compassHolder,
    bool isHostile
): LivingEntity{pos, race, hp, atk, def, passive}, compassHolder{compassHolder}, isHostile{isHostile} {
    money = Currency{1, 0};
}

void Enemy::attack() {
    if (getLength() > 0) {
        notifyObservers("attack");
    }
}

void Enemy::onDeath() {
    notifyObservers("drop_gold");
}
void Enemy::giveCompass(){
    compassHolder = true;
}
// Observer Methods
void Enemy::notify(Subject& whoNotified, string action) {
    try {
        LivingEntity& entity = dynamic_cast<LivingEntity&>(whoNotified);

        if (action == "attack") {
            int dmg = ceil(100.0f/(100 + def) * entity.getAtk());
            // if dragonsuit, dmg = ceil(dmg/2);
            hp -= dmg;
            if (hp <= 0) {
                hp = 0;
                onDeath();
            }
        }

    } catch(bad_cast &e) {
        cerr << e.what() << endl;
    }
}
bool Enemy::getCompassHolder() const {
    return compassHolder;
}
bool Enemy::getIsHostile() const {
    return isHostile;
}
Passive* Enemy::getPassive() const {
    return passive;
}

string Enemy::getName() { return "Enemy"; }

Enemy::~Enemy() {}