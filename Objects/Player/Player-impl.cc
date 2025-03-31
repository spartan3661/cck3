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
    Race race,
    int hp,
    int atk,
    int def,
    Passive *passive
):
    LivingEntity{pos, race, hp, atk, def, passive}, score{0}
{}

void Player::attack() {
    notifyObservers("attack");
}

void Player::use() {

}


// getters
int Player::getHp() const {
    string type = "hp";
    int effect_total = 0;
    if (effects) { effect_total = effects->getEffect(type); }

    // check if hp is within range
    if (effect_total + hp > maxhp) { effect_total = 0; }
    if (effect_total + hp < 0) { effect_total = -hp; }

    return effect_total + hp;
}

int Player::getAtk() const {
    string type = "atk";
    int effect_total = 0;
    if (effects) { effect_total = effects->getEffect(type); }
    return effect_total + atk;
}

int Player::getDef() const {
    string type = "def";
    int effect_total = 0;
    if (effects) { effect_total = effects->getEffect(type); }
    return effect_total + def;
}

int Player::getScore() const { return score; }


void Player::addEffect(StatusEffect *effect) {
    if (effect) {
        effect->setNext(effects);
        effects = effect;
    }
}

void Player::equipItem(Item* item) {
    inventory.emplace_back(item);
}

void Player::equipArmour(Item* item) {
    armour.emplace_back(item);
}

void Player::decrementEffects() {
    // decrement effects
    if (effects) {
        effects->decrementDuration();
    }

    // keep track of  StatusEffect pointers
    StatusEffect *prev = nullptr;
    StatusEffect *next = effects->getNext();
    StatusEffect *cur = effects;

    while (next) {
        if (cur->getDuration() == 0) {
            cur->setNext(nullptr);

            // link previous and next status effect
            if (prev) {
                prev->setNext(next);
            } else {
                effects = next;
            }

            // move cur and next forward
            cur = next;
            next = cur->getNext();

        } else {
            // move all pointers forward by one
            prev = cur;
            cur = next;
            next = cur->getNext();
        }
    }
}

void Player::setScore(int s) { score = s; }


// Observer Methods
void Player::notify(Subject& whoNotified, string action) {
    try {

        LivingEntity& entity = dynamic_cast<LivingEntity&>(whoNotified);

        if (action == "attack") {
            int dmg = ceil(100.0f/(100 + def) * entity.getAtk());
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