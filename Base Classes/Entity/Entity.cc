export module entity;
import position;

export class Entity {
    Position coords;

    public:
        Entity(int x, int y);
        Position getCoords() const;
        virtual ~Entity() = 0;
};