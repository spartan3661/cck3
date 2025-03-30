module board;
import player;
import item;
import enemy;
import textDisplay;
import Position;
import passive;

import <fstream>;
import <iostream>;
import <string>;
import <vector>;
import <tuple>;
import <random>;

using namespace std;

Board::Board(): currentLevel{1}, chambers{5} {
    
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


    itemSample = {
        //...
    
    };

    
}



void Board::init(Race r){
    
    readLevel();
    
    td = TextDisplay{refBoard};

    unsigned seed = 42;
    std::default_random_engine rng{seed};

    //spawn player

    int playerIndex = spawnPlayer(rng, r);

    //spawn staircase
    spawnStairs(std::default_random_engine& rng, playerIndex)
    //spawn enemies
    spawnEnemies(rng);
}
void Board::clearBoard(){
    displayBoard.clear();
    refBoard.clear();
    readLevel();


}

int Board::spawnPlayer(std::default_random_engine& rng, Race r){
    for ( int i = 0; i < 10; i++ ) {
		std::shuffle( chamberSample.begin(), chamberSample.end(), rng );
        
	}
    for ( int i = 0; i < 10; i++ ) {
		std::shuffle( chambers[chamberSample[0]].begin(), chambers[chamberSample[0]].end(), rng );
        
	}
    
    Position entityPos{chambers[chamberSample[0]][0], chambers[chamberSample[0]][1]};

    plr = new Player{entityPos, r, 120, 20, 20, nullptr};

    chambers[chamberSample[0]][0].erase(chambers.start());
    return chamberSample[0];
}

void Board::spawnStairs(std::default_random_engine& rng, int playerIndex){
    while(chamberSample[0] != playerIndex) {
        for ( int i = 0; i < 10; i++ ) {
            std::shuffle( chamberSample.begin(), chamberSample.end(), rng );
        }
    }

    for ( int i = 0; i < 10; i++ ) {
		std::shuffle( chambers[chamberSample[0]].begin(), chambers[chamberSample[0]].end(), rng );
        
	}

    Position entityPos{chambers[chamberSample[0]][0], chambers[chamberSample[0]][1]};

    refBoard[chambers[chamberSample[0]][0]][chambers[chamberSample[0]][1]] = '\\';

    chambers[chamberSample[0]][0].erase(chambers.start());
}

void Board::spawnEnemies(std::default_random_engine& rng){
    for ( int i = 0; i < 20; i++ ) {
        for ( int i = 0; i < 10; i++ ) {
            std::shuffle( chamberSample.begin(), chamberSample.end(), rng );
            
        }
        for ( int i = 0; i < 10; i++ ) {
            std::shuffle( chambers[chamberSample[0]].begin(), chambers[chamberSample[0]].end(), rng );
            std::shuffle( enemySample.begin(), enemySample.end(), rng );
            std::shuffle( enemyDistribution.begin(), enemyDistribution.end(), rng );
        }

        Position entityPos{chambers[chamberSample[0]][0], chambers[chamberSample[0]][1]};

        Enemy tempEnemy = enemy{enemyDistribution[0]};
        tempEnemy.setCoords{entityPos};
        enemies.emplace_back(tempEnemy)
        chambers[chamberSample[0]][0].erase(chambers.start());

	}
}
void Board::spawnItems(std::default_random_engine& rng){
    for ( int i = 0; i < 20; i++ ) {
        for ( int i = 0; i < 10; i++ ) {
            std::shuffle( chamberSample.begin(), chamberSample.end(), rng );
            
        }
        for ( int i = 0; i < 10; i++ ) {
            std::shuffle( chambers[chamberSample[0]].begin(), chambers[chamberSample[0]].end(), rng );
            std::shuffle( item.begin(), item.end(), rng );
            std::shuffle( itemDistribution.begin(), itemDistribution.end(), rng );
        }

        Position entityPos{chambers[chamberSample[0]][0], chambers[chamberSample[0]][1]};

        Item tempItem = Item{enemyDistribution[0]};
        tempItem.setCoords{entityPos};
        items.emplace_back(tempEnemy)
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

