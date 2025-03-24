export module position;
import <iostream>;
import <compare>;
import <string>;

export enum class Direction {NO = 0, NE, EA, SE, SO, SW, WE, NW};

// Outputs the string that is equivalent to the enumerated type's value.
// export std::ostream &operator<<(std::ostream& out, const Direction& dir);

export class Position {
    int x, y;
    public:
        Position(int x, int y);

        // Adds rhs.x to this position's x and rhs.y to this position's y.
        Position& operator+=(const Position& rhs);

        // Subtracts rhs.x from this position's x and rhs.y from this position's y.
        Position& operator-=(const Position& rhs);

        int getX() const;
        int getY() const;

};

// Returns std::strong_ordering::equal if lhs == rhs. Checks x-coordinate first, then
// y-coordinate. Performs minimal number of checks.
export std::strong_ordering operator<=>(const Position& lhs, const Position& rhs);

// Prints the current values of the position to out in the format: (x, y)
export std::ostream &operator<<(std::ostream& out, const Position& pos);