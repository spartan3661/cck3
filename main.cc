import <iostream>;
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

using namespace std;

int main() {

    // TEST CURRENCY AND POSITION

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
    Enemy enemy{{0, 0}, Race::GOBLIN, 50, 10, 10};
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
}