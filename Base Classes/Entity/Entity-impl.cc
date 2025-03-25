module entity;
import position;

using namespace std;

Entity::Entity(Position pos): coords{pos} {}

Entity::getCoords() const { return coords }

Entity::~Entity() {}