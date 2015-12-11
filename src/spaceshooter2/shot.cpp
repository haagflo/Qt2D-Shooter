#include "shot.h"

// one shot of the shuttle

Shot::Shot() : LinearMovingItems() {
}

Shot::Shot(qreal rot, qreal spd) : LinearMovingItems(rot, spd) {
    width = 3;
    height = 10;
    setData(classTypeKey, shot);
}

void Shot::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) {
    QImage image(":/images/shot2.png");
    painter->drawImage(QRectF(0,0,width,height), image);
}

void Shot::advance(int step)
{
    LinearMovingItems::advance(step);
    deleteIfCollidesWith(asteroid);
}
