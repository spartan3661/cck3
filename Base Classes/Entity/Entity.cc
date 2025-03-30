export module entity;
import position;

export class Entity {
    protected:
        Position coords;
    public:
        Entity(Position pos);
        Position getCoords() const;

        void setCoords(Position pos);
        virtual ~Entity() = 0;
};