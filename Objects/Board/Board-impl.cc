module board;
import player;
import item;
import enemy;
import textDisplay;
import Position;
import passive;
import barrierSuit;

import <fstream>;
import <iostream>;
import <string>;
import <vector>;
import <tuple>;
import <random>;

using namespace std;

Board::Board(): currentLevel{1}, maxEnemies{20} {
    
    for (int i = 0; i < numChambers; i++){
        chamberSample[i] = i;
    }

    enemySample = {Enemy{Pos{0,0}, Race::Werewolf, 50, 25, 25, false, true},
                   Enemy{Pos{0,0}, Race::Vampire, 120, 30, 5, false, true}.
                   Enemy{Pos{0,0}, Race::Goblin, 70, 5, 10, false, true},
                   Enemy{Pos{0,0}, Race::Troll, 120, 25, 15, false, true},
                   Enemy{Pos{0,0}, Race::Phoenix, 50, 35, 20, false, true},
                   Enemy{Pos{0,0}, Race::Merchant, 30, 70, 7, false, false}
    };
    enemyDistribution = {0, 0, 0, 0,
                         1, 1, 1,
                         2, 2, 2, 2, 2,
                         3, 3,
                         4, 4,
                         5, 5};


    potionSample = {
        Potion{"Restore Health", 5, nullptr},
        Potion{"Poison Health", 5, nullptr},
        Potion{"Boost Attack", 5, nullptr},
        Potion{"Boost Def", 5, nullptr};
        Potion{"Wound Attack", 5, nullptr},
        Potion{"Wound Def", 5, nullptr};
    };

    goldSample = {
        GoldPile{"normal", 1},
        GoldPile{"small hoard", 2},
        GoldPile{"dragon hoard", 4}
    };

    goldDistribution = {0, 0, 0, 0, 0,
                        1, 1,
                        2
    };

    
}



void Board::init(Race r){
    unsigned seed = 42;
    std::default_random_engine rng{seed};


    readLevel(rng);
    
    td = TextDisplay{refBoard};


    //spawn player

    int playerIndex = spawnPlayer(rng, r);

    //spawn staircase
    spawnStairs(rng, playerIndex)

    spawnPotionsAndGold(rng);

    //spawn enemies
    spawnEnemies(rng);
}
void Board::clearBoard(){
    displayBoard.clear();
    refBoard.clear();
    readLevel();


}

int Board::spawnPlayer(std::default_random_engine& rng, Race r){

	std::shuffle( chamberSample.begin(), chamberSample.end(), rng );
	std::shuffle( chambers[chamberSample[0]].begin(), chambers[chamberSample[0]].end(), rng );
        
    
    Position entityPos{chambers[chamberSample[0]][0], chambers[chamberSample[0]][1]};

    plr = new Player{entityPos, r, 120, 20, 20, nullptr};

    chambers[chamberSample[0]][0].erase(chambers.start());
    return chamberSample[0];
}

void Board::spawnStairs(std::default_random_engine& rng, int playerIndex){
    while(chamberSample[0] != playerIndex) {
        std::shuffle( chamberSample.begin(), chamberSample.end(), rng );
    }


	std::shuffle( chambers[chamberSample[0]].begin(), chambers[chamberSample[0]].end(), rng );
        


    Position entityPos{chambers[chamberSample[0]][0], chambers[chamberSample[0]][1]};

    refBoard[chambers[chamberSample[0]][0]][chambers[chamberSample[0]][1]] = '\\';

    chambers[chamberSample[0]][0].erase(chambers.start());
}

void Board::spawnEnemies(std::default_random_engine& rng){
    for ( int i = 0; i < maxEnemies; i++ ) {

        std::shuffle( chamberSample.begin(), chamberSample.end(), rng );
        std::shuffle( chambers[chamberSample[0]].begin(), chambers[chamberSample[0]].end(), rng );
        std::shuffle( enemyDistribution.begin(), enemyDistribution.end(), rng );
        

        Position entityPos{chambers[chamberSample[0]][0], chambers[chamberSample[0]][1]};
        if(i == 1){
            Enemy tempEnemy = enemy{enemySample[enemyDistribution[0]]};
            tempEnemy.giveCompass();
        } else{
            Enemy tempEnemy = enemy{enemySample[enemyDistribution[0]]};
        }
        
        tempEnemy.setCoords{entityPos};
        enemies.emplace_back(tempEnemy)
        chambers[chamberSample[0]][0].erase(chambers.start());

	}
}

void Board::spawnPotionGoldSuit(std::default_random_engine& rng){
    if(!barrierSuitSpawned){
        std::bernoulli_distribution dist(0.5);
        bool spawn = dist(rng);
        if (spawn){
            Position entityPos{0, 0};

            if(goldSample[goldDistribution[0]].getName() == "dragon hoard"){
                vector<tuple> randomDragonPos = {make_tuple<1, 1>,
                    make_tuple<1, -1>,
                    make_tuple<-1, 1>,
                    make_tuple<-1, -1>,
                    make_tuple<0, 1>,
                    make_tuple<0, -1>,
                    make_tuple<-1, 0>,
                    make_tuple<0, -1>
                }
    
                do{
                    for ( int i = 0; i < 10; i++ ) {
                        std::shuffle( chambers[chamberSample[0]].begin(), chambers[chamberSample[0]].end(), rng);
                        std::shuffle( chamberSample.begin(), chamberSample.end(), rng );
                    }
    
                    entityPos{chambers[chamberSample[0]][0], chambers[chamberSample[0]][1]};
    
                    for(auto posMod : randomDragonPos){
                        dragonPosition = make_tuple<entityPos.getX() + posMod[0][0], 
                                                    entityPos.getY() + posMod[0][1]>;
                        if(find(chambers[chamberSample[0]].begin(), chambers[chamberSample[0]].end(), dragonPosition) != chambers[chamberSample[0]].end()){
                            newDragonPos.push_back(dragonPosition);
                        }
                    }
                } while {!newDragonPos.empty()};
            }
    
            Item tempSuit = Item{BarrierSuit{"suit"}};
            tempSuit.setCoords{entityPos};
    
            std::shuffle(newDragonPos.begin(), newDragonPos.end(), rng);
            enemies.emplace_back(Enemy{Position{newDragonPos[0][0], newDragonPos[0][1]}, Race::Dragon, 150, 20, 20});
    
            maxEnemies--;
    
            items.emplace_back(tempSuit)
            chambers[chamberSample[0]][0].erase(chambers.start());
        }

    }


    for ( int i = 0; i < 10; i++ ) {

        std::shuffle( chamberSample.begin(), chamberSample.end(), rng );
        std::shuffle( chambers[chamberSample[0]].begin(), chambers[chamberSample[0]].end(), rng );
        std::shuffle( potionSample.begin(), potionSample.end(), rng );

        Position entityPos{chambers[chamberSample[0]][0], chambers[chamberSample[0]][1]};

        Item tempPotion = Item{potionSample[0]};
        tempPotion.setCoords{entityPos};
        items.emplace_back(tempPotion)
        chambers[chamberSample[0]][0].erase(chambers.start());

	}

    vector<tuple> newDragonPos;

    for ( int i = 0; i < 10; i++ ) {

        std::shuffle( goldDistribution.begin(), goldDistribution.end(), rng );


        Position entityPos{0, 0};

        if(goldSample[goldDistribution[0]].getName() == "dragon hoard"){
            vector<tuple> randomDragonPos = {make_tuple<1, 1>,
                make_tuple<1, -1>,
                make_tuple<-1, 1>,
                make_tuple<-1, -1>,
                make_tuple<0, 1>,
                make_tuple<0, -1>,
                make_tuple<-1, 0>,
                make_tuple<0, -1>
            }

            do{
                for ( int i = 0; i < 10; i++ ) {
                    std::shuffle( chambers[chamberSample[0]].begin(), chambers[chamberSample[0]].end(), rng);
                    std::shuffle( chamberSample.begin(), chamberSample.end(), rng );
                }

                entityPos{chambers[chamberSample[0]][0], chambers[chamberSample[0]][1]};

                for(auto posMod : randomDragonPos){
                    dragonPosition = make_tuple<entityPos.getX() + posMod[0][0], 
                                                entityPos.getY() + posMod[0][1]>;
                    if(find(chambers[chamberSample[0]].begin(), chambers[chamberSample[0]].end(), dragonPosition) != chambers[chamberSample[0]].end()){
                        newDragonPos.push_back(dragonPosition);
                    }
                }
            } while {!newDragonPos.empty()};
        }

        Item tempGold = Item{goldSample[goldDistribution[0]]};
        tempGold.setCoords{entityPos};

        std::shuffle(newDragonPos.begin(), newDragonPos.end(), rng);
        enemies.emplace_back(Enemy{Position{newDragonPos[0][0], newDragonPos[0][1]}, Race::Dragon, 150, 20, 20});

        maxEnemies--;

        items.emplace_back(tempGold)
        chambers[chamberSample[0]][0].erase(chambers.start());

	}
    
}

void Board::tick(){

}

void Board::display(){
    //std::cout << "\033[2J\033[1;1H";
    td.printBoard(plr, boardState);


    
}


void Board::readLevel(){

    string file = "./levels/level" + to_string(currentLevel) + ".txt";
    ifstream levelFile(file);

    char ch;
    numChambers = levelFile.get(ch) - '0';
    chambers.resize(numChambers);

    string line;
    int row = 0;

    while (getline(levelFile, line)) {
        vector<char> tempVector;
        for (int col = 0; col < line.size(); ++col) {
            char ch = line[col];
            tempVector.push_back(ch);

            if (isdigit(ch)) {
                int index = ch - '0';
                chambers[index].push_back(std::make_tuple(row, col));
            }
        }
        refBoard.emplace_back(tempVector);
        displayBoard.emplace_back(tempVector);
        row++;
    }
}

