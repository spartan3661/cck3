module item;
import <string>;
//import player;
//import board;

using namespace std;

string Item::getName() const { return name }

bool Item::canPickup() const { return canPickup }

void Item::pickupItem() {}

void Item::useItem() {}

Item::~Item() {}