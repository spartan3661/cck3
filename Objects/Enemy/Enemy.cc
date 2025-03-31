export module enemy;
import <string>;
import livingEntity;
import position;
import passive;

export class Enemy: public LivingEntity {
    protected:
        bool compassHolder;
        bool isHostile;
    
    public:
        Enemy(Position pos, Race race, int hp, int atk, int def, Passive *passive, bool compassHolder = false, bool isHostile = true);
        
        void attack() override;

        virtual void onDeath(); // params: Board& b
        void giveCompass();
        // observer methods
        void notify(Subject& whoNotified, std::string action) override; // is called when someone interacts with me.
        std::string getName() override;
        Passive* getPassive() const;

        bool getCompassHolder() const;
        bool getIsHostile() const;

        ~Enemy() override;
};