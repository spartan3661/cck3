export module board;
import player;
import item;
import enemy;
import textDisplay;
import position;
import potion;
import GoldPile;
import <vector>;
import <string>;
import <tuple>;

export class Board{ 

    Player *plr;

    int numChambers;
    int maxEnemies;
    bool barrierSuitSpawned;
    
    std::vector<std::vector<char>> chambers;
    std::vector<int> chamberSample;

    std::vector<int> enemyDistribution;
    std::vector<Enemy*> enemySample;
    std::vector<Enemy*> enemies;

    std::vector<Potion*> potionSample;
    std::vector<int> goldDistribution;
    std::vector<GoldPile*> goldSample;

    std::vector<Item*> items;           //holds actual items

    std::vector<std::vector<char>> refBoard;
    std::vector<std::vector<char>> displayBoard;

    TextDisplay td;
    std::string boardState;


    public:
        Board();
        void init(Race r);
        void clearBoard();
        int spawnPlayer(std::default_random_engine& rng, Race r);
        void spawnStairs(std::default_random_engine& rng);
        void spawnEnemies(std::default_random_engine& rng);
        void spawnPotionsAndGold(std::default_random_engine& rng);
        void spawn
        void tick();
        void display();

        // helpers
        void readLevel();



};
