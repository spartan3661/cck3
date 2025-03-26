module player;
import <iostream>;
import <vector>;
import <string>;
import <cmath>;
import <memory>;
import item;
import livingEntity;
import statusEffect;

using namespace std;

Player::Player(
    Position pos,
    Race race = Race::HUMAN,
    int hp = 140,
    int atk = 20,
    int def = 20,
    Passive *passive = nullptr // new MultiplyScore{1.5}
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
    try {

        LivingEntity& entity = dynamic_cast<LivingEntity&>(whoNotified);

        if (action == "attack") {
            int dmg = ceil(100/(100 + def) * entity.getAtk());
            // if dragonsuit, dmg = ceil(dmg/2);
            hp -= dmg;
        } else if (action == "drop_gold") {
            money += entity.getMoney();
        }
        
    } catch(bad_cast &e) {
        cerr << e.what() << endl;
    }
}

string Player::getName() { return "Player"; }

// Subject Methods
Player::~Player() {}