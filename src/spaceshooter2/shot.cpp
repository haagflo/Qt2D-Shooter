#include "shot.h"

// one shot of the shuttle

Shot::Shot() : LinearMovingItems() {
}

Shot::Shot(qreal rot, qreal spd) : LinearMovingItems(rot, spd) {
}

QRectF Shot::boundingRect() const {
    return QRectF(0, 0, width, height);
}

QPainterPath Shot::shape() const {
    QPainterPath path;
    path.addRect(0, 0, width, height);
    return path;
}

void Shot::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) {
    QImage image(":/images/shot2.png");
    painter->drawImage(QRectF(0,0,width,height), image);
}
