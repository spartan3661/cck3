module entity;
import position;

using namespace std;

Entity::Entity(Position pos): coords{pos} {}

Position Entity::getCoords() const { return coords; }
void setCoords(Position pos){
    coords = pos;
}
Entity::~Entity() {}