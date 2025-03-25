module enemy;
import <vector>;
import position;

Enemy::Enemy(
    Position pos,
    Race race,
    int hp,
    int atk,
    int def,
    bool compasHolder = false,
    bool isHostile = true
):
    LivingEntity{pos, race, hp, atk, def}
{
    this.compasHolder = compasHolder;
    this.isHostile = isHostile;
}

void Enemy::attack() {
    if (this.observers.length() > 0) {
        notifyObservers("attack");
    }
}

void Enemy::onDeath() {
    notifyObservers("drop_gold");
}


// Observer Methods
void Enemy::notify(Subject& whoNotified, string action) {
    if (action == "attack") {
        int dmg = ceil(100/(100 + def) * whoNotified.getAtk());
        hp -= dmg;
    }
}

string Enemy::getName() { return "Enemy"; }

// Subject Methods
Enemy::~Subject() {}