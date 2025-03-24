export module passive;
import <string>;

using namespace std;

export class Passive {
    string type;
    public:
        string getType() const;
        virtual void passiveEffect() = 0;
};