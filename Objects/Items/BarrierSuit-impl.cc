module barrierSuit;
import <string>;
import position;
import item;

using namespace std;

BarrierSuit::BarrierSuit(Position pos, string name) : Item{pos, name, false} {}

BarrierSuit::~BarrierSuit() {}