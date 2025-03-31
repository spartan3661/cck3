module item;
import <iostream>;
import <string>;
import <memory>;
import entity;
import livingEntity;
import currency;
import position;
//import board;

using namespace std;

Item::Item(Position pos, string name, bool pickupable, Currency price): Entity{pos}, name{name}, pickupable{pickupable}, price{price} {}

string Item::getName() const { return name; }

Currency Item::getPrice() const { return price; }

bool Item::canPickup() const { return pickupable; }

void Item::pickupItem(LivingEntity& to) {}

void Item::useItem() {}

Item::~Item() {}