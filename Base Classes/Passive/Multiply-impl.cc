module multiply;
import <iostream>;
import <string>;
import <memory>;
import <cmath>;
import passive;
import livingEntity;
import player;
import currency;

using namespace std;

Multiply::Multiply(string type, float multiplier): Passive{type}, multiplier{multiplier} {}

void Multiply::passiveEffect() {}

void Multiply::passiveEffect(LivingEntity& to, Currency pickup) {
    if (type == "gold"){
        int totalSilver = pickup.getGold() * 100 + pickup.getSilver();
        int newAmount = static_cast<int>(round(totalSilver * multiplier));
        int newGold = newAmount / 100;
        int newSilver = newAmount % 100;
        to.addMoney(Currency{newGold, newSilver});

    } else if (type == "score"){
        try {
            Player& plr = dynamic_cast<Player&>(to);
            int newScore = static_cast<int>(round(plr.getScore() * multiplier));
            plr.setScore(newScore);
        } catch(bad_cast &e) {
            cerr << e.what() << endl;
        }
    }
}