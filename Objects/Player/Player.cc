export module player;
import <vector>;
import <string>;
import livingEntity;
import statusEffect;
import position;
import passive;
import item;

export class Player: public LivingEntity {
    std::vector<Item*> inventory;
    std::vector<Item*> armour;
    StatusEffect *effects;
    std::vector<std::string> knownPotions;

    public:
        Player(Position pos, Race race = Race::HUMAN, int hp = 140, int atk = 20, int def = 20, Passive *passive = nullptr); // new MultiplyScore{1.5}
        
        void attack() override;
        void use();

        // getters
        int getHp() const override;
        int getAtk() const override;
        int getDef() const override;

        void addEffect(StatusEffect *effect);
        void decrementEffects();

        // observer methods
        void notify(Subject& whoNotified, std::string action) override; // is called when someone interacts with me.
        std::string getName() override;

        // subject methods
        ~Player() override;
        friend StatusEffect;
};