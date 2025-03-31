export module compass;
import item;
import <string>;

export class Compass : public Item {

    public:
        Compass(std::string name);               
        ~Compass() override;
};