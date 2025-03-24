module position;
import <iostream>;
import <compare>;
import <string>;

using namespace std;

ostream& operator<<(ostream& out, const Direction& dir) {
    static const string strValues[] = {"North", "North-East", "East", "South-East", "South", "South-West", "West", "North-West"};
    out << strValues[static_cast<int>(dir)];
    return out;
}

Position::Position(int x, int y): x{x}, y{y} {}

Position & Position::operator+=(const Position& rhs) {
    x += rhs.x;
    y += rhs.y;
    return *this;
}

Position & Position::operator-=(const Position& rhs) {
    x -= rhs.x;
    y -= rhs.y;
    return *this;
}

int Position::getX() const { return x; }
int Position::getY() const { return y; }

std::strong_ordering operator<=>(const Position& lhs, const Position& rhs) {
    auto res_x = lhs.getX() <=> rhs.getX();
    if (res_x != 0) return res_x;
    return lhs.getY() <=> rhs.getY();
}

std::ostream &operator<<(std::ostream& out, const Position& pos) {
    out << "(" << pos.getX() << ", " << pos.getY() << ")";
    return out;
}
