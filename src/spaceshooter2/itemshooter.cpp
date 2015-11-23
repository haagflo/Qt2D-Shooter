
#include "itemshooter.h"

ItemShooter::ItemShooter() {

}

ItemShooter::ItemShooter(int x, int y, QGraphicsScene* scene) :
x(x), y(y), scene(scene) {

    Item* i = new Item();
    i->setPos(this->x, this->y);
    scene->addItem(i);

}




