module stealing;
import passive;
import currency;
import livingEntity;

Stealing::Stealing(int amount) : type{"hp"}, amount{amount} {}
void Stealing::passiveEffect() override {}
void Stealing::passiveEffect(LivingEntity& to, LivingEntity& from) {
    if (type == "hp"){
        if(to.health + amount > to.maxHp){
            to.health = to.maxHp;
        } else{
            to.health += amount;
        }
        
        if(from.health - amount < 0){
            from.health = 0;
        } else{
            from.health -= amount;
        }
    
    } else{
        Currency tempCurrency{from.money};
        if(tempCurrency - Currency{amount, 0} < Currency{0,0}){
            from.money = Currency{0, 0};
        } else{
            from.money -= Currency{amount, 0};
        }
    }
}