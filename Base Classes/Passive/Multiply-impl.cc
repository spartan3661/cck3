module multiply;
import passive;
import livingEntity;
import <memory>;

Multiply::Multiply(float multiplier) : type{"gold"}, multiplier{multiplier} {}
void Multiply::passiveEffect() override {}
void Multiply::passiveEffect(LivingEntity& to, Currency pickup) {
    if (type = "gold"){
        tempCurrency = Currency{pickup};
        int totalSilver = tempCurrency.getGold(); * 100 + tempCurrency.getSilver();;
        int newAmount = static_cast<int>(round(totalSilver * multiplier));
        int newGold = newAmount / 100;
        int newSilver = newAmount % 100;
        to.money = Currency{newGold, newSilver};

    }
    if (type = "score"){
        int newScore = static_cast<int>(round(to.score * multiplier));
        to.score = newScore;
    }
}