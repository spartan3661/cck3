module dragon;
import livingEntity;
import enemy;
import item;
import position;

Dragon::Dragon(Position pos, Item* treasure):
    Enemy{pos, Race::DRAGON, 150, 20, 20, false, false},
    treasure{treasure}
{}
void Dragon::onDeath() {

}