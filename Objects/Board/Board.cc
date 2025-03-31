export module board;
import livingEntity;
import player;
import item;
import enemy;
import textDisplay;
import position;
import potion;
import goldPile;
import <random>;
import <vector>;
import <string>;
import <tuple>;

export class Board{ 

    Player *plr;

    int numChambers;
    int maxEnemies;
    int currentLevel;
    bool barrierSuitSpawned;
    
    std::vector<std::vector<std::tuple<int, int>>> chambers;
    std::vector<int> chamberSample;

    std::vector<int> enemyDistribution;
    std::vector<Enemy*> enemySample;
    std::vector<Enemy*> enemies;
    std::vector<char> enemySymbols;

    std::vector<Potion> potionSample;
    std::vector<int> goldDistribution;
    std::vector<GoldPile> goldSample;

    std::vector<Item*> items;           //holds actual items

    std::vector<std::vector<char>> refBoard;
    std::vector<std::vector<char>> displayBoard;

    TextDisplay td;
    std::string boardState;


    public:
        Board();
        //~Board();
        void init(Race r);
        void clearBoard();
        Player& getPlayer();
        int spawnPlayer(std::default_random_engine& rng, Race r);
        void movePlayer(Position pos);
        void spawnStairs(std::default_random_engine& rng, int playerIndex);
        void spawnEnemies(std::default_random_engine& rng);
        void spawnItems(std::default_random_engine& rng);

        void tick();
        void display();

        // helpers
        void readLevel();
        void spawnBarrierSuit(std::default_random_engine& rng);
        void spawnPotion(std::default_random_engine& rng);
        void spawnGold(std::default_random_engine& rng);
        
};
