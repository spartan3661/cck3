module board;
import player;
import item;
import enemy;
import dragon;
import textDisplay;
import position;

import passive;
import stealing;
import healthRegen;
import multiply;
import negatePotion;

import barrierSuit;
import currency;

import <fstream>;
import <iostream>;
import <string>;
import <vector>;
import <tuple>;
import <random>;
import <algorithm>;
import <chrono>;

using namespace std;

Board::Board():  maxEnemies{20}, currentLevel{1} {

    seed = std::chrono::system_clock::now().time_since_epoch().count();
    rng = default_random_engine{seed};
    
    enemySample = {
        new Enemy{Position{0,0}, Race::WEREWOLF, 50, 25, 25, nullptr, false, true},
        new Enemy{Position{0,0}, Race::VAMPIRE, 120, 20, 5, new Stealing{"hp", 10}, false, true},
        new Enemy{Position{0,0}, Race::GOBLIN, 70, 5, 10, new Stealing{"gold", 1}, false, true},
        new Enemy{Position{0,0}, Race::TROLL, 120, 25, 15, new HealthRegen{5}, false, true},
        new Enemy{Position{0,0}, Race::PHOENIX, 50, 35, 20, nullptr, false, true},
        new Enemy{Position{0,0}, Race::MERCHANT, 30, 70, 7, nullptr, false, false}
    };

    enemySymbols = { 'W', 'V', 'N', 'T', 'X', 'M' };

    enemyDistribution = {
        0, 0, 0, 0,
        1, 1, 1,
        2, 2, 2, 2, 2,
        3, 3,
        4, 4,
        5, 5
    };


    potionSample = {
        Potion{Position{0,0}, "Restore Health", Currency{0, 0}, nullptr},
        Potion{Position{0,0}, "Boost Attack", Currency{0, 0}, nullptr},
        Potion{Position{0,0}, "Boost Def", Currency{0, 0}, nullptr},
        Potion{Position{0,0}, "Poison Health", Currency{0, 0}, nullptr},
        Potion{Position{0,0}, "Wound Attack", Currency{0, 0}, nullptr},
        Potion{Position{0,0}, "Wound Def", Currency{0, 0}, nullptr}
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

/*
Board::~Board() {
    for (auto e : enemySample) {
        delete[] e;
    }
    for (auto e : enemies) {
        delete[] e;
    }
    for (auto e : items) {
        delete[] e;
    }
}
*/


void Board::init(Race r){

    readLevel();
    
    td = TextDisplay{&displayBoard};

    // spawn player
    int playerIndex = spawnPlayer(rng, r);

    // spawn staircase
    spawnStairs(rng, playerIndex);

    // spawn items
    spawnItems(rng);

    // spawn enemies
    spawnEnemies(rng);
}

void Board::readLevel(){

    string file = "./levels/level" + to_string(currentLevel) + ".txt";
    ifstream levelFile(file);

    char ch;
    levelFile.get(ch);
    numChambers = ch - '0';
    chambers.resize(numChambers);

    for (int i = 0; i < numChambers; i++){
        chamberSample.push_back(i);
    }

    string line;
    int row = 0;

    // read in text file to generate room
    while (getline(levelFile, line)) {
        vector<char> tempVector;
        for (size_t col = 0; col < line.size(); ++col){
            char ch = line[col];
            tempVector.push_back(ch);

            if (isdigit(ch)) {
                int index = ch - '0' - 1;
                chambers[index].push_back(make_tuple(row, col));
            }
        }
        refBoard.emplace_back(tempVector);
        displayBoard.emplace_back(tempVector);
        row++;
    }
}

Player& Board::getPlayer() {
    return *plr;
};

void Board::clearBoard(){
    displayBoard.clear();
    refBoard.clear();
    readLevel();
}

int Board::spawnPlayer(default_random_engine& rng, Race r){

	shuffle( chamberSample.begin(), chamberSample.end(), rng );
	shuffle( chambers[chamberSample[0]].begin(), chambers[chamberSample[0]].end(), rng );
        
    
    Position entityPos{get<0>(chambers[chamberSample[0]][0]), get<1>(chambers[chamberSample[0]][0])};

    // change stats based on class
    plr = new Player{entityPos, r, 120, 20, 20, nullptr};
    displayBoard[plr->getX()][plr->getY()] = '@';
    // cout << entityPos << endl;

    chambers[chamberSample[0]].erase(chambers[chamberSample[0]].begin());

    return chamberSample[0];
}

void Board::spawnStairs(default_random_engine& rng, int playerIndex){
    while(chamberSample[0] == playerIndex) {
        // cout << chamberSample[0] << ": " << playerIndex << endl;
        shuffle( chamberSample.begin(), chamberSample.end(), rng );
    }

	shuffle( chambers[chamberSample[0]].begin(), chambers[chamberSample[0]].end(), rng );
    
    Position entityPos{get<0>(chambers[chamberSample[0]][0]), get<1>(chambers[chamberSample[0]][0])};

    displayBoard[get<0>(chambers[chamberSample[0]][0])][get<1>(chambers[chamberSample[0]][0])] = '\\';

    chambers[chamberSample[0]].erase(chambers[chamberSample[0]].begin());

}

void Board::spawnEnemies(default_random_engine& rng){
    bool compassHolder = true;
    for ( int i = 0; i < maxEnemies; i++ ) {

        shuffle( chamberSample.begin(), chamberSample.end(), rng );
        shuffle( chambers[chamberSample[0]].begin(), chambers[chamberSample[0]].end(), rng );
        shuffle( enemyDistribution.begin(), enemyDistribution.end(), rng );
        
        // select enemy position
        Position entityPos{get<0>(chambers[chamberSample[0]][0]), get<1>(chambers[chamberSample[0]][0])};
        
        // initialize enemy
        Enemy* base = enemySample[enemyDistribution[0]];
        Enemy tempEnemy{Position{entityPos}, base->getRace(), base->getHp(), base->getAtk(), base->getDef(), base->getPassive(), compassHolder, base->getIsHostile()};
        
        // update display on board
        displayBoard[entityPos.getX()][entityPos.getY()] = enemySymbols[enemyDistribution[0]];

        // add to enemy list
        enemies.emplace_back(new Enemy{tempEnemy});
        

        if (i == 0) { compassHolder = false; };

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
        if (spawn || currentLevel == 5){
            vector<tuple<int, int>> newDragonPos;

            barrierSuitSpawned = true;
            Position entityPos{0, 0};
            BarrierSuit* bSuit = new BarrierSuit{entityPos, "suit"};
            
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
            
            bSuit->setCoords(entityPos);
    
            shuffle(newDragonPos.begin(), newDragonPos.end(), rng);

            Position dpos{std::get<0>(newDragonPos[0]), std::get<1>(newDragonPos[0]), Direction::NO};
            enemies.emplace_back(new Dragon{dpos, bSuit});

            // update display on board
            displayBoard[dpos.getX()][dpos.getY()] = 'D';
            
            maxEnemies--;
            items.emplace_back(bSuit);

            // update display on board
            displayBoard[entityPos.getX()][entityPos.getY()] = 'B';
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

        // set spawn position
        Position entityPos{get<0>(chambers[chamberSample[0]][0]), get<1>(chambers[chamberSample[0]][0])};

        // update display on board
        displayBoard[entityPos.getX()][entityPos.getY()] = 'P';

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

        GoldPile tempGold{goldSample[goldDistribution[0]]};

        if(goldSample[goldDistribution[0]].getName() == "dragon hoard"){
            do{
                newDragonPos.clear();

                for ( int i = 0; i < 10; i++ ) {
                    shuffle( chambers[chamberSample[0]].begin(), chambers[chamberSample[0]].end(), rng);
                    shuffle( chamberSample.begin(), chamberSample.end(), rng );
                }

                Position entityPos = Position{get<0>(chambers[chamberSample[0]][0]), get<1>(chambers[chamberSample[0]][0])};
                tempGold.setCoords(entityPos);

                for(auto posMod : randomDragonPos){
                    tuple<int, int> dragonPosition = make_tuple(entityPos.getX() + get<0>(posMod), 
                                                                entityPos.getY() + get<1>(posMod));
                    if(find(chambers[chamberSample[0]].begin(), chambers[chamberSample[0]].end(), dragonPosition) != chambers[chamberSample[0]].end()){
                        newDragonPos.push_back(dragonPosition);
                    }
                }
            } while (newDragonPos.empty());

            shuffle(newDragonPos.begin(), newDragonPos.end(), rng);
            Position dpos{std::get<0>(newDragonPos[0]), std::get<1>(newDragonPos[0]), Direction::NO};
            enemies.emplace_back(new Dragon{dpos, &tempGold});

            // update display on board
            displayBoard[dpos.getX()][dpos.getY()] = 'D';
            maxEnemies--;

        } else {
            for ( int i = 0; i < 10; i++ ) {
                shuffle( chambers[chamberSample[0]].begin(), chambers[chamberSample[0]].end(), rng);
                shuffle( chamberSample.begin(), chamberSample.end(), rng );
            }

            Position entityPos = Position{get<0>(chambers[chamberSample[0]][0]), get<1>(chambers[chamberSample[0]][0])};
            tempGold.setCoords(entityPos);
        }
        
        // add to item list
        items.emplace_back(new GoldPile{tempGold});

        // update display on board
        displayBoard[tempGold.getX()][tempGold.getY()] = 'G';
        chambers[chamberSample[0]].erase(chambers[chamberSample[0]].begin());
	}
}
void Board::spawnItems(default_random_engine& rng){
    spawnPotion(rng);
    spawnBarrierSuit(rng);
    spawnGold(rng);
}

void Board::movePlayer(Position pos) {
    Position old_pos = plr->getCoords();
    Position new_pos = plr->getCoords();
    new_pos += pos;
    tuple<int, int> tpl = make_tuple(new_pos.getX(), new_pos.getY());
    for (auto& v : chambers) {
        for (auto& col : v) {
            if (col == tpl) {
                plr->move(pos);
                // cout << plr->getCoords() << endl;
                v.push_back(make_tuple(old_pos.getX(), old_pos.getY()));
                displayBoard[old_pos.getX()][old_pos.getY()] = refBoard[old_pos.getX()][old_pos.getY()];
                displayBoard[plr->getX()][plr->getY()] = '@';
                break;
            }
        }
        /*
        if (iter != v.end()) {
            Position temp = plr->getCoords();
            plr->move(pos);
            cout << plr->getCoords() << endl;
            v.push_back(make_tuple(temp.getX(), temp.getY()));
            displayBoard[temp.getX()][temp.getY()] = refBoard[temp.getX()][temp.getY()];
            displayBoard[plr->getX()][plr->getY()] = '@';
            break;
        }*/
    }
}

bool Board::moveEnemy(Position pos, Enemy* en, char c) {
    Position old_pos = en->getCoords();
    Position new_pos = en->getCoords();
    new_pos += pos;
    tuple<int, int> tpl = make_tuple(new_pos.getX(), new_pos.getY());
    for (auto& v : chambers) {
        for (auto& col : v) {
            if (col == tpl) {
                en->move(pos);
                // cout << plr->getCoords() << endl;
                v.push_back(make_tuple(old_pos.getX(), old_pos.getY()));
                displayBoard[old_pos.getX()][old_pos.getY()] = refBoard[old_pos.getX()][old_pos.getY()];
                displayBoard[en->getX()][en->getY()] = c;
                return true;
            }
        }
    }
    return false;
}

void Board::tick(){
    vector<Position> choices = {
        Position{1, 0, Direction::SO},
        Position{0, 1, Direction::EA},
        Position{0, -1, Direction::WE},
        Position{-1, 1, Direction::NE},
        Position{-1, -1, Direction::NW},
        Position{1, -1, Direction::SW},
        Position{-1, 0, Direction::NO},
        Position{1, 1, Direction::SE},
    };

    for (auto en : enemies) {
        shuffle(choices.begin(), choices.end(), rng);

        for (auto pos : choices) {
            if (moveEnemy(pos, en, displayBoard[en->getX()][en->getY()])) {
                break;
            }
        }

    }
    display();
}

void Board::display(){
    //cout << "\033[2J\033[1;1H";
    //cout << displayBoard[plr->getX()][plr->getY()] << endl;
    td.printBoard(plr, boardState);
}

