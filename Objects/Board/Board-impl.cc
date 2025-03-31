module board;
import player;
import item;
import enemy;
import textDisplay;
import position;
import passive;
import barrierSuit;
import currency;

import <fstream>;
import <iostream>;
import <string>;
import <vector>;
import <tuple>;
import <random>;
import <algorithm>;

using namespace std;

Board::Board():  maxEnemies{20}, currentLevel{1} {
    
    for (int i = 0; i < numChambers; i++){
        chamberSample[i] = i;
    }

    enemySample = {new Enemy{Position{0,0}, Race::WEREWOLF, 50, 25, 25, false, true},
                   new Enemy{Position{0,0}, Race::VAMPIRE, 120, 30, 5, false, true},
                   new Enemy{Position{0,0}, Race::GOBLIN, 70, 5, 10, false, true},
                   new Enemy{Position{0,0}, Race::TROLL, 120, 25, 15, false, true},
                   new Enemy{Position{0,0}, Race::PHOENIX, 50, 35, 20, false, true},
                   new Enemy{Position{0,0}, Race::MERCHANT, 30, 70, 7, false, false}
    };

    enemyDistribution = {0, 0, 0, 0,
                         1, 1, 1,
                         2, 2, 2, 2, 2,
                         3, 3,
                         4, 4,
                         5, 5
    };


    potionSample = {
        Potion{Position{0,0}, "Restore Health", 5, nullptr},
        Potion{Position{0,0}, "Poison Health", 5, nullptr},
        Potion{Position{0,0}, "Boost Attack", 5, nullptr},
        Potion{Position{0,0}, "Boost Def", 5, nullptr},
        Potion{Position{0,0}, "Wound Attack", 5, nullptr},
        Potion{Position{0,0}, "Wound Def", 5, nullptr}
    };
                        

    goldSample = {
        GoldPile{Position{0,0}, "normal", Currency{1, 0}},
        GoldPile{Position{0,0}, "small hoard", Currency{2, 0}},
        GoldPile{Position{0,0}, "dragon hoard", Currency{4, 0}}
    };

    goldDistribution = {0, 0, 0, 0, 0,
                        1, 1,
                        2
    };

    
}



void Board::init(Race r){
    unsigned seed = 42;
    default_random_engine rng{seed};


    readLevel();
    
    td = TextDisplay{refBoard};


    //spawn player

    int playerIndex = spawnPlayer(rng, r);

    //spawn staircase
    spawnStairs(rng, playerIndex);

    spawnItems(rng);

    //spawn enemies
    spawnEnemies(rng);
}
void Board::clearBoard(){
    displayBoard.clear();
    refBoard.clear();
    readLevel();


}

int Board::spawnPlayer(default_random_engine& rng, Race r){

	shuffle( chamberSample.begin(), chamberSample.end(), rng );
	shuffle( chambers[chamberSample[0]].begin(), chambers[chamberSample[0]].end(), rng );
        
    
    Position entityPos{get<0>(chambers[chamberSample[0]][0]), get<1>(chambers[chamberSample[0]][0])};

    plr = new Player{entityPos, r, 120, 20, 20, nullptr};

    chambers[chamberSample[0]].erase(chambers[chamberSample[0]].begin());

    return chamberSample[0];
}

void Board::spawnStairs(default_random_engine& rng, int playerIndex){
    while(chamberSample[0] != playerIndex) {
        shuffle( chamberSample.begin(), chamberSample.end(), rng );
    }


	shuffle( chambers[chamberSample[0]].begin(), chambers[chamberSample[0]].end(), rng );
        


    Position entityPos{get<0>(chambers[chamberSample[0]][0]), get<1>(chambers[chamberSample[0]][0])};

    refBoard[get<0>(chambers[chamberSample[0]][0])][get<1>(chambers[chamberSample[0]][0])] = '\\';

    chambers[chamberSample[0]].erase(chambers[chamberSample[0]].begin());

}

void Board::spawnEnemies(default_random_engine& rng){
    for ( int i = 0; i < maxEnemies; i++ ) {

        shuffle( chamberSample.begin(), chamberSample.end(), rng );
        shuffle( chambers[chamberSample[0]].begin(), chambers[chamberSample[0]].end(), rng );
        shuffle( enemyDistribution.begin(), enemyDistribution.end(), rng );
        
        
        Position entityPos{get<0>(chambers[chamberSample[0]][0]), get<1>(chambers[chamberSample[0]][0])};
        if(i == 1){
            Enemy* base = enemySample[enemyDistribution[0]];
            Enemy tempEnemy{Position{entityPos}, base->getRace(), base->getHp(), base->getAtk(), base->getDef(), true, base->getIsHostile()};

            enemies.emplace_back(new Enemy{tempEnemy});
        } else{
            Enemy* base = enemySample[enemyDistribution[0]];
            Enemy tempEnemy{Position{entityPos}, base->getRace(), base->getHp(), base->getAtk(), base->getDef(), false, base->getIsHostile()};
;
            enemies.emplace_back(new Enemy{tempEnemy});
        }

        chambers[chamberSample[0]].erase(chambers[chamberSample[0]].begin());


	}
}

/**
 * Helper for spawnItems
 * 
 * 
 * 
 */
void Board::spawnBarrierSuit(default_random_engine& rng){
    vector<tuple<int, int>> randomDragonPos = {
        make_tuple(1, 1),
        make_tuple(1, -1),
        make_tuple(-1, 1),
        make_tuple(-1, -1),
        make_tuple(0, 1),
        make_tuple(0, -1),
        make_tuple(-1, 0),
        make_tuple(1, 0)
    };

    if(!barrierSuitSpawned){
        bernoulli_distribution dist(0.5);
        bool spawn = dist(rng);
        if (spawn){
            vector<tuple<int, int>> newDragonPos;

            barrierSuitSpawned = true;
            Position entityPos{0, 0};

            if(goldSample[goldDistribution[0]].getName() == "dragon hoard"){
                do{
                    newDragonPos.clear();
                    for ( int i = 0; i < 10; i++ ) {
                        shuffle( chambers[chamberSample[0]].begin(), chambers[chamberSample[0]].end(), rng);
                        shuffle( chamberSample.begin(), chamberSample.end(), rng );
                    }
    
                    entityPos = Position{get<0>(chambers[chamberSample[0]][0]), get<1>(chambers[chamberSample[0]][0])};
    
                    for(auto posMod : randomDragonPos){
                        tuple<int, int> dragonPosition = make_tuple(entityPos.getX() + get<0>(posMod), 
                                                                    entityPos.getY() + get<1>(posMod));
                        if(find(chambers[chamberSample[0]].begin(), chambers[chamberSample[0]].end(), dragonPosition) != chambers[chamberSample[0]].end()){
                            newDragonPos.push_back(dragonPosition);
                        }
                    }
                } while (newDragonPos.empty());
            }
    
            shuffle(newDragonPos.begin(), newDragonPos.end(), rng);
            enemies.emplace_back(new Enemy{Position{std::get<0>(newDragonPos[0]), 
                std::get<1>(newDragonPos[0]), Direction::NO}, 
                Race::DRAGON, 150, 20, 20, false, false}); //make sure dragon can spawn with compass
    
            maxEnemies--;
    
            items.emplace_back(new BarrierSuit{entityPos, "suit"});
            chambers[chamberSample[0]].erase(chambers[chamberSample[0]].begin());

        }

    }
}

/**
 * Helper for spawnPotion
 * 
 * 
 * 
 */
void Board::spawnPotion(default_random_engine& rng){
    for ( int i = 0; i < 10; i++ ) {

        shuffle( chamberSample.begin(), chamberSample.end(), rng );
        shuffle( chambers[chamberSample[0]].begin(), chambers[chamberSample[0]].end(), rng );
        shuffle( potionSample.begin(), potionSample.end(), rng );

        Position entityPos{get<0>(chambers[chamberSample[0]][0]), get<1>(chambers[chamberSample[0]][0])};

        Potion tempPotion{potionSample[0]};
        tempPotion.setCoords(entityPos);
        items.emplace_back(new Potion{tempPotion});
        chambers[chamberSample[0]].erase(chambers[chamberSample[0]].begin());
	}
}

/**
 * Helper for spawnGold
 * 
 * 
 * 
 */
void Board::spawnGold(default_random_engine& rng){
    vector<tuple<int, int>> randomDragonPos = {
        make_tuple(1, 1),
        make_tuple(1, -1),
        make_tuple(-1, 1),
        make_tuple(-1, -1),
        make_tuple(0, 1),
        make_tuple(0, -1),
        make_tuple(-1, 0),
        make_tuple(1, 0)
    };
    vector<tuple<int, int>> newDragonPos;

    for ( int i = 0; i < 10; i++ ) {

        shuffle( goldDistribution.begin(), goldDistribution.end(), rng );

        Position entityPos{0, 0};

        if(goldSample[goldDistribution[0]].getName() == "dragon hoard"){
            do{
                newDragonPos.clear();
                for ( int i = 0; i < 10; i++ ) {
                    shuffle( chambers[chamberSample[0]].begin(), chambers[chamberSample[0]].end(), rng);
                    shuffle( chamberSample.begin(), chamberSample.end(), rng );
                }

                entityPos = Position{get<0>(chambers[chamberSample[0]][0]), get<1>(chambers[chamberSample[0]][0])};

                for(auto posMod : randomDragonPos){
                    tuple<int, int> dragonPosition = make_tuple(entityPos.getX() + get<0>(posMod), 
                                                                entityPos.getY() + get<1>(posMod));
                    if(find(chambers[chamberSample[0]].begin(), chambers[chamberSample[0]].end(), dragonPosition) != chambers[chamberSample[0]].end()){
                        newDragonPos.push_back(dragonPosition);
                    }
                }
            } while (newDragonPos.empty());
        }

        GoldPile tempGold{goldSample[goldDistribution[0]]};
        tempGold.setCoords(entityPos);

        shuffle(newDragonPos.begin(), newDragonPos.end(), rng);
        enemies.emplace_back(new Enemy{Position{std::get<0>(newDragonPos[0]), 
            std::get<1>(newDragonPos[0]), Direction::NO}, 
            Race::DRAGON, 150, 20, 20, false, false});

        maxEnemies--;

        items.emplace_back(new GoldPile{tempGold});
        chambers[chamberSample[0]].erase(chambers[chamberSample[0]].begin());


	}
}
void Board::spawnItems(default_random_engine& rng){
    spawnPotion(rng);
    spawnBarrierSuit(rng);
    spawnGold(rng);
}

void Board::tick(){

}

void Board::display(){
    //cout << "\033[2J\033[1;1H";
    td.printBoard(plr, boardState);


    
}


void Board::readLevel(){

    string file = "./levels/level" + to_string(currentLevel) + ".txt";
    ifstream levelFile(file);

    char ch;
    levelFile.get(ch);
    numChambers = ch - '0';
    chambers.resize(numChambers);

    string line;
    int row = 0;

    while (getline(levelFile, line)) {
        vector<char> tempVector;
        for (size_t col = 0; col < line.size(); ++col){
            char ch = line[col];
            tempVector.push_back(ch);

            if (isdigit(ch)) {
                int index = ch - '0';
                chambers[index].push_back(make_tuple(row, col));
            }
        }
        refBoard.emplace_back(tempVector);
        displayBoard.emplace_back(tempVector);
        row++;
    }
}

