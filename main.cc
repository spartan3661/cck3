import <iostream>;
import currency;
import position;
import subject_observer;
import livingEntity;
import player;
import enemy;

using namespace std;

int main() {
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
}