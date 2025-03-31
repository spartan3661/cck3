export module dragon;
import enemy;
import item;
import position;

export class Dragon: public Enemy {
    Item* treasure;
    public:
        Dragon(Position pos, Item* treasure);
        void onDeath() override;
};
