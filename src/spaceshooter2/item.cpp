
#include "item.h"

Item::Item(){
    width = 35;
    height = 35;
    setData(classTypeKey, item);
}

void Item::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) {
QImage image;

    if(ItemType == 0) {
        image.load(":/images/weapons3.jpg");
    }
    else if(ItemType == 1) {
        image.load(":/images/life2.jpg");
    }

    painter->drawImage(QRectF(0,0,width,height), image);
}

void Item::advance(int step) {
    if (!step)
        return;

    deleteIfCollidesWith(shuttle);
}

