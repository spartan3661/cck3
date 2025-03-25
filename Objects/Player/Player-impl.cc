module player;
import <vector>;
import <string>;
import <cmath>;
import item;

using namespace std;

Player::Player(
    Position pos,
    Race race = Race::HUMAN,
    int hp = 140,
    int atk = 20,
    int def = 20,
    Passive passive* = nullptr // new MultiplyScore{1.5}
):
    LivingEntity{pos, race, hp, atk, def}
{
    effects = nullptr;
}

void Player::attack() {
    notifyObservers("attack");
}

void Player::defend() {

}

void Player::use() {

}

// Observer Methods
void Player::notify(Subject& whoNotified, string action) {
    if (action == "attack") {
        int dmg = ceil(100/(100 + def) * whoNotified.getAtk());
        // if dragonsuit, dmg = ceil(dmg/2);
        this.hp -= dmg;
    } else if (action == "drop_gold") {
        this.money += whoNotified.getMoney();
    }
}

string Player::getName() { return "Player"; }

// Subject Methods
Player::~Subject() {}