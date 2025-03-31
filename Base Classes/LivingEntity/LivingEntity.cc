export module livingEntity;
import <vector>;
import entity;
import subject_observer;
import currency;
import position;
import passive;

export enum class Race {
    HUMAN,
    ELF,
    ORC,
    DWARF,
    WEREWOLF,
    VAMPIRE,
    GOBLIN,
    MERCHANT,
    DRAGON,
    PHOENIX,
    TROLL
};

export class LivingEntity: public Entity, public Observer, public Subject {
    protected:
        Race race;
        const int maxhp;
        int hp, atk, def;
        Currency money;
        std::vector<Entity*> neighbours;
        Passive *passive;

    public:
        LivingEntity(Position pos, Race race, int hp, int atk, int def);

        int getHp() const;
        int getAtk() const;
        int getDef() const;

        Currency getMoney() const;

        // adds displacement to current position and changes
        // direction to displacement's direction.
        void move(Position displacement);
        virtual void attack() = 0;
        friend class Passive;
};