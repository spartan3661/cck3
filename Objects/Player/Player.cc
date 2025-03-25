export module player;
import <vector>;
import <string>;
import position;
import passive;
import item;

export class Player: public LivingEntity {
    std::vector<Item*> inventory;
    std::vector<Item*> armour;
    StatusEffect *effects;
    std::vector<std::string> knownPotions;

    public:
        Player(Position pos, Race race, int hp, int atk, int def, Passive *passive);
        void attack() override;
        void defend();
        void use();

        // observer methods
        void notify(Subject& whoNotified, string action) override; // is called when someone interacts with me.
        std::string getName() override;

        // subject methods
        ~Subject() override;
};