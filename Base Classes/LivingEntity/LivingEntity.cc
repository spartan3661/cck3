export module livingEntity;
import <vector>;
import entity;
import currency;

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

export class LivingEntity: public Entity {
    int hp, atk, def;
    Race race;
    Currency money;
    std::vector<Entity*> neighbours;

    public:
        int getHp() const;
        int getAtk() const;
        int getDef() const;
        Currency getCurrency() const;

        void move();
        virtual void attack() = 0;
}