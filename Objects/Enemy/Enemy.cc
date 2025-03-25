export module enemy;
import position;

export class Enemy: public LivingEntity {
    bool compasHolder;
    bool isHostile;
    public:
        Enemy(Position pos, Race race, int hp, int atk, int def, bool compasHolder, bool isHostile);
        
        void attack() override;
        void onDeath(); // params: Board& b

        // observer methods
        void notify(Subject& whoNotified, string action) override; // is called when someone interacts with me.
        std::string getName() override;

        // subject methods
        ~Subject() override;
};