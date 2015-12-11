
#include "item.h"

Item::Item(){
    width = 30;
    height = 30;
    setData(classTypeKey, item);
}

void Item::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) {
      QImage image(":/images/item_feature.png");
      painter->drawImage(QRectF(0,0,width,height), image);
}

void Item::advance(int step) {
    if (!step)
        return;

    deleteIfCollidesWith(shuttle);
}


