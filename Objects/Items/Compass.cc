export module compass;
import item;
import <string>;
import position;

export class Compass : public Item {

    public:
        Compass(Position pos, std::string name);               
        ~Compass() override;
};