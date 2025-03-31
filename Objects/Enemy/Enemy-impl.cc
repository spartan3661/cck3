module enemy;
import <vector>;
import <string>;
import <cmath>;
import <iostream>;
import <memory>;
import position;
import livingEntity;

using namespace std;

Enemy::Enemy(
    Position pos,
    Race race,
    int hp,
    int atk,
    int def,
    bool compassHolder,
    bool isHostile
): LivingEntity{pos, race, hp, atk, def}, compassHolder{compassHolder}, isHostile{isHostile} {}

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
            int dmg = ceil(100/(100 + def) * entity.getAtk());
            // if dragonsuit, dmg = ceil(dmg/2);
            hp -= dmg;
        }

    } catch(bad_cast &e) {
        cerr << e.what() << endl;
    }
}

string Enemy::getName() { return "Enemy"; }

Enemy::~Enemy() {}