export module barrierSuit;
import <string>;
import item;
import position;

export class BarrierSuit : public Item {
    public:
        BarrierSuit(Position pos, std::string name);
        ~BarrierSuit() override;
};