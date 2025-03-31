module entity;
import position;

using namespace std;

Entity::Entity(Position pos): coords{pos} {}

Position Entity::getCoords() const { return coords; }

int Entity::getX() const { return coords.getX(); }
int Entity::getY() const { return coords.getY(); }

void Entity::setCoords(Position pos){
    coords = pos;
}
Entity::~Entity() {}