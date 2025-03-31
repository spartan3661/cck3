export module barrierSuit;
import <string>;
import position;
import item;

export class BarrierSuit : public Item {
    public:
        BarrierSuit(Position pos, std::string name);
        ~BarrierSuit() override;
};