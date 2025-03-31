export module livingEntity;
import <vector>;
import <iostream>;
import entity;
import subject_observer;
import currency;
import position;
import passive;

export enum class Race {
    HUMAN = 0,
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

// Outputs the string that is equivalent to the enumerated type's value.
export std::ostream &operator<<(std::ostream& out, const Race& race);

export class LivingEntity: public Entity, public Observer, public Subject {
    protected:
        Race race;
        const int maxhp;
        int hp, atk, def;
        Passive *passive;
        Currency money;
        std::vector<Entity*> neighbours;

    public:
        LivingEntity(Position pos, Race race, int hp, int atk, int def, Passive *passive);

        // getters
        int getMaxHp() const;
        virtual int getHp() const;
        virtual int getAtk() const;
        virtual int getDef() const;

        Currency getMoney() const;
        Race getRace() const;

        // setter
        void addMoney(Currency amount);
        void subMoney(Currency amount);
        void addHp(int amount);
        void subHp(int amount);

        // adds displacement to current position and changes
        // direction to displacement's direction.
        void move(Position displacement);
        virtual void attack(Direction dir) = 0;
        friend class Passive;
};