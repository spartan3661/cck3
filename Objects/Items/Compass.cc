export module compass;
import item;
import position;
import <string>;

export class Compass : public Item {

    public:
        Compass(Position pos, std::string name);               
        ~Compass() override;
};