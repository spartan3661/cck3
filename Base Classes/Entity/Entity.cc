export module entity;
import position;

export class Entity {
    Position coords;

    public:
        Entity(Position pos);
        Position getCoords() const;
        virtual ~Entity() = 0;
        friend LivingEntity;
};