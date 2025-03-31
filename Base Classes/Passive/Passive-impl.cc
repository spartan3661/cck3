module passive;
import <string>;

using namespace std;

Passive::Passive(string type): type{type} {}

string Passive::getType() const { return type; }

void Passive::passiveEffect() {}