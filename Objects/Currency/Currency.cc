export module currency;
import <iostream>;
import <compare>;
import <string>;

using namespace std;

export class Currency {
    int gold, silver;

    public:
        Currency(int gold, int silver);

        Currency& operator+=(const Currency& rhs);
        Currency& operator-=(const Currency& rhs);

        int getGold() const;
        int getSilver() const;
};

// Returns std::strong_ordering::equal if lhs == rhs. Checks gold first, then
// silver. Performs minimal number of checks.
export strong_ordering operator<=>(const Currency& lhs, const Currency& rhs);

// Prints the current currency value to out in the format: [gold]G, [silver]S
export ostream &operator<<(ostream& out, const Currency& c);