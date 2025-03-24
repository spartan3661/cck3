module currency;
import <iostream>;
import <compare>;
import <string>;

using namespace std;

Currency::Currency(int gold, int silver): gold{gold}, silver{silver} {}

Currency& Currency::operator+=(const Currency& rhs) {

    int temp = silver + rhs.silver;
    int remainder = temp % 100;

    gold += rhs.gold + (temp - remainder) / 100;
    silver += remainder;
    
    return *this;
}

Currency& Currency::operator-=(const Currency& rhs) {
    gold -= rhs.gold;
    silver -= rhs.silver;
    return *this;
}

int Position::getGold() const { return gold; }
int Position::getSilver() const { return silver; }

strong_ordering operator<=>(const Currency& lhs, const Currency& rhs) {
    auto res_g = lhs.getGold() <=> rhs.getGold();
    if (res_g != 0) return res_g;
    return lhs.getSilver() <=> rhs.getSilver();
}

ostream &operator<<(ostream& out, const Currency& c) {
    out << c.getGold() << "G, " << c.getSilver() << "S";
    return out;
}
