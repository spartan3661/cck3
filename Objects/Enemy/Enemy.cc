export module enemy;
import <string>;
import livingEntity;
import position;

export class Enemy: public LivingEntity {
    protected:
        bool compassHolder;
        bool isHostile;
    
    public:
        Enemy(Position pos, Race race, int hp, int atk, int def, bool compassHolder = false, bool isHostile = true);
        
        void attack() override;

        virtual void onDeath(); // params: Board& b

        void onDeath(); // params: Board& b
        void giveCompass();
        // observer methods
        void notify(Subject& whoNotified, std::string action) override; // is called when someone interacts with me.
        std::string getName() override;

        bool getCompassHolder() const;
        bool getIsHostile() const;

        ~Enemy() override;
};