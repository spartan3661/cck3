export module merchant;
import <vector>;
import <string>;
import livingEntity;
import enemy;
import player;
import position;
import item;
import potion;

export class Merchant: public Enemy {
    std::vector<Item*> shop_items;
    std::vector<int> stock;
    public:
        Merchant(Position pos);
        void onDeath() override;
        void notify(Subject& whoNotified, std::string action) override; // is called when someone interacts with me.
        void printShop();
        void purchase(Player& plr, int shop_index);
};