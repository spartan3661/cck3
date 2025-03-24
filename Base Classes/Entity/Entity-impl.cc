module entity;
import position;

using namespace std;

Entity::Entity(int x, int y): coords{x, y} {}

Entity::getCoords() const { return coords }

Entity::~Entity() {}