export module barrierSuit;
import <string>;
import item;

export class BarrierSuit : public Item {
    public:
        BarrierSuit(std::string name);
        ~BarrierSuit() override;
};