import <iostream>;
import <string>;
import position;
import player;
import board;
import textDisplay;


using namespace std;

int main() {
    Board b;
    
    string command;
    bool raceChosen = false;
    while (cin >> command) {
        if (command == "q") {
            break;
        } else if (command == "r") {
            b.clear();
            b.init();
            b.display();
        } else if ((command == "h" || command == "e" || command == "d" || command == "o") && hasChosen != true) {
            Race r = Race::HUMAN;
            if (command == "e") {
                r = Race::ELF;
            }else if (command == "d") {
                r = Race::DWARF;
            }else {
                r = Race::ORC;
            }
            b.init(r);
        } else if (command == "no" || command == "so" || command == "ea" || command == "we" ||
                   command == "ne" || command == "nw" || command == "se" || command == "sw") {
                    Player& ref = b.getPlayer();
                    switch(direction){
                        case direction == "no":
                            ref.move{Position{0, 1, Direction::NO}};
                            break;
                        case direction == "so":
                            ref.move{Position{0, -1, Direction::SO}};
                            break;
                        case direction == "ea":
                            ref.move{Position{1, 0, Direction::EA}};
                            break;
                        case direction == "we":
                            ref.move{Position{-1, 0, Direction::WE}};
                            break;
                        case direction == "ne":
                            ref.move{Position{-1, 1, Direction::NE}};
                            break;
                        case direction == "nw":
                            ref.move{Position{-1, -1, Direction::NW}};
                            break;
                        case direction == "se":
                            ref.move{Position{1, 1, Direction::SE}};
                            break;
                        case direction == "sw":
                            ref.move{Position{1, -1, Direction::SW}};
                            break;
                    }

        } else if (command == "u" || command == "a") {
            string direction;
            cin >> direction;
            Direction r = Direction::NO;
            switch(direction){
                case direction == "no":
                    r = Direction::NO;
                    break;
                case direction == "so":
                    r = Direction::SO;
                    break;
                case direction == "ea":
                    r = Direction::EA;
                    break;
                case direction == "we":
                    r = Direction::WE;
                    break;
                case direction == "ne":
                    r = Direction::NE;
                    break;
                case direction == "nw":
                    r = Direction::NW;
                    break;
                case direction == "se":
                    r = Direction::SE;
                    break;
                case direction == "sw":
                    r = Direction::SE;
                    break;
            }

            Player& ref = b.getPlayer();
            if (command == "u") {
                ref.move(Position{0,0, r})
            }else{
                ref.attack();
            }
        }
        b.tick();
    }
}