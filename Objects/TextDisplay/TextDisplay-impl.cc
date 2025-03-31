module textDisplay;
import livingEntity;
import player;
import <vector>;
import <string>;
import <iostream>;

using namespace std;

TextDisplay::TextDisplay(std::vector<std::vector<char>>* display) : display{display} {}

void TextDisplay::printBoard(const Player* plr, string boardState) const {
    for (const auto& row : *display) {
        for (char c : row) {
            if (isdigit(c)) {
                cout << '.';
            } else {
                cout << c;
            }
        }
        cout << endl;
    }
    cout << "Race: " << plr->getRace() << " Gold: " << plr->getMoney().getGold() << endl;
    cout << "HP: " << plr->getHp() << endl;
    cout << "ATK: " << plr->getAtk() << endl;
    cout << "DEF: " << plr->getDef() << endl;
    cout << "Action: " << boardState << endl;
}

std::ostream& operator<<(std::ostream& os, const TextDisplay& td){
    for (const auto& row : *td.display) {
        for (char c : row) {
            os << c;
        }
        os << endl;
    }
    return os;
}
