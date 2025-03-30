export module compass;
import item;
import <string>;
using namespace std;

export class Compass : public Item {

    public:
        Compass(string name);               
        void pickupItem(Player *plr, Board& b) override;
        

}