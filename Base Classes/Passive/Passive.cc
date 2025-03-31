export module passive;
import <string>;

using namespace std;

export class Passive {
    protected:
        string type;
    public:
        Passive(std::string type);
        string getType() const;
        virtual void passiveEffect() = 0;
};