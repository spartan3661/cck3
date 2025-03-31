module stealing;
import <string>;
import passive;
import currency;
import livingEntity;

using namespace std;

Stealing::Stealing(string type, int amount): Passive{type}, amount{amount} {}

void Stealing::passiveEffect() {}

void Stealing::passiveEffect(LivingEntity& to, LivingEntity& from) {
    if (type == "hp"){
        to.addHp(amount);
        from.subHp(amount);

    } else if (type == "gold") {
        to.addMoney(Currency{amount, 0});
        from.subMoney(Currency{amount, 0});
    }
}