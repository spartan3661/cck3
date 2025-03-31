module compass;
import <string>;
import position;
import item;

using namespace std;

Compass::Compass(Position pos, string name): Item{pos, name} {}

Compass::~Compass() {}