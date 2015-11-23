#ifndef ITEMSHOOTER
#define ITEMSHOOTER

#include "item.h"

class ItemShooter {

public:
    ItemShooter();
    ItemShooter(int xPos, int yPos, QGraphicsScene* scene);
    ~ItemShooter() {}

    void shootItem();

private:
    int x;
    int y;
    QGraphicsScene* scene;
};

#endif
