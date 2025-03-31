import <iostream>;
import <string>;
import currency;
import position;
import subject_observer;
import livingEntity;
import player;
import enemy;
import merchant;
import dragon;

import barrierSuit;
import compass;
import goldPile;
import potion;

import healthEffect;
import atkEffect;
import defEffect;

import board;
import textDisplay;

using namespace std;

int main() {
    Board b;
    string command;
    bool hasChosen = false;

    while (cin >> command) {
        if (command == "q") {
            break;
        } else if (command == "r") {
            b.clearBoard();
            b.display();
        } else if ((command == "h" || command == "e" || command == "d" || command == "o") && hasChosen != true) {
            Race r;
            if (command == "e") {
                r = Race::ELF;
            } else if (command == "d") {
                r = Race::DWARF;
            } else if (command == "o"){
                r = Race::ORC;
            } else {
                r = Race::HUMAN;
            }
            b.init(r);
        } else if(command == "no" || command == "so" || command == "ea" || command == "we" ||
            command == "ne" || command == "nw" || command == "se" || command == "sw") {
            Player& ref = b.getPlayer();
            if (command == "no") {
                b.movePlayer(Position{-1, 0, Direction::NO});
            } else if (command == "so") {
                b.movePlayer(Position{1, 0, Direction::SO});
            } else if (command == "ea") {
                b.movePlayer(Position{0, 1, Direction::EA});
            } else if (command == "we") {
                b.movePlayer(Position{0, -1, Direction::WE});
            } else if (command == "ne") {
                b.movePlayer(Position{-1, 1, Direction::NE});
            } else if (command == "nw") {
                b.movePlayer(Position{-1, -1, Direction::NW});
            } else if (command == "se") {
                b.movePlayer(Position{1, 1, Direction::SE});
            } else if (command == "sw") {
                ref.move(Position{1, -1, Direction::SW});
            } 
        } else if (command == "u" || command == "a") {
            //Player& ref = b.getPlayer();
            Position p{0, 0, Direction::NO};
            string direction;
            cin >> direction;
            if (direction == "no") {
                p = Position{-1, 0, Direction::NO};
            } else if (direction == "so") {
                p = Position{1, 0, Direction::SO};
            } else if (direction == "ea") {
                p = Position{0, 1, Direction::EA};
            } else if (direction == "we") {
                p = Position{0, -1, Direction::WE};
            } else if (direction == "ne") {
                p = Position{-1, 1, Direction::NE};
            } else if (direction == "nw") {
                p = Position{-1, -1, Direction::NW};
            } else if (direction == "se") {
                p = Position{-1, 1, Direction::SE};
            } else if (direction == "sw") {
                p = Position{1, -1, Direction::SW};
            } 

            if (command == "u") {
                //ref.use(r);
                b.playerUse(p);
            } else {
                //ref.attack(r);
                b.playerAttack(p);
            }
        }
        b.tick();
    }

    // TEST CURRENCY AND POSITION
    
    /*
    Currency c{5, 20};
    Position p{10, 10, Direction::NO};

    cout << c << endl;
    cout << p << endl;
    cout << p.getDir() << endl;

    c += Currency{0, 550};

    p.changeDir(Direction::SE);
    p += Position{200, -100};

    cout << c << endl;
    cout << p << endl;
    cout << p.getDir() << endl;

    // TEST PLAYER AND ENEMY

    Player plr{{0, 0}};
    Enemy enemy{{0, 0}, Race::GOBLIN, 50, 10, 10, nullptr};
    Merchant merch{{0, 0}};

    plr.attach(&enemy);
    enemy.attach(&plr);
    merch.attach(&plr);
    enemy.attach(&merch);

    cout << plr.getLength() << endl;
    cout << enemy.getLength() << endl;

    cout << plr.getHp() << endl;
    cout << enemy.getHp() << endl;
    cout << plr.getMoney() << endl;

    cout << "-ATTACK-" << endl;
    plr.notifyObservers("attack");
    enemy.notifyObservers("attack");

    cout << plr.getHp() << endl;
    cout << enemy.getHp() << endl;
    cout << plr.getMoney() << endl;

    cout << plr.getName() << endl;
    cout << enemy.getName() << endl;

    cout << "PLAYER STATS:" << endl;
    cout << plr.getAtk() << endl;
    cout << plr.getDef() << endl;
    cout << plr.getMoney() << endl;

    cout << "-ADD EFFECTS-" << endl;
    plr.addEffect(new HealthEffect{true});
    plr.addEffect(new AtkEffect{false});
    plr.addEffect(new AtkEffect{false});
    plr.addEffect(new AtkEffect{false});
    plr.addEffect(new AtkEffect{false});
    plr.addEffect(new DefEffect{false});

    cout << "PLAYER STATS:" << endl;
    cout << plr.getAtk() << endl;
    cout << plr.getDef() << endl;
    cout << plr.getMoney() << endl;

    cout << plr.getHp() << endl;
    cout << enemy.getHp() << endl;

    cout << "-ATTACK-" << endl;
    plr.notifyObservers("attack");
    enemy.notifyObservers("attack");
    
    cout << plr.getHp() << endl;
    cout << enemy.getHp() << endl;
    cout << plr.getMoney() << endl;

    plr.decrementEffects();
    cout << "PLAYER STATS:" << endl;
    cout << plr.getAtk() << endl;
    cout << plr.getDef() << endl;
    cout << plr.getMoney() << endl;

    plr.addMoney(Currency{50, 0});

    merch.printShop();
    merch.purchase(plr, 20);
    merch.purchase(plr, 0);
    merch.purchase(plr, 1);
    merch.purchase(plr, 2);

    cout << "STATS:" << endl;
    cout << plr.getHp() << endl;
    cout << enemy.getHp() << endl;
    cout << plr.getMoney() << endl;
    
    cout << "PLAYER STATS:" << endl;
    cout << plr.getAtk() << endl;
    cout << plr.getDef() << endl;
    cout << plr.getMoney() << endl;
    */
}