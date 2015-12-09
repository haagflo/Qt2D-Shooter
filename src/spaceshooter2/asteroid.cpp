#include "asteroid.h"

Asteroid::Asteroid(){
}

Asteroid::Asteroid(qreal rot, qreal spd) : LinearMovingItems(rot, spd) {
    setData(classType, asteroid);
}

QRectF Asteroid::boundingRect() const {
    return QRectF(0, 0, width, height);
}

QPainterPath Asteroid::shape() const {
    QPainterPath path;
    path.addRect(0,0, width, height);
    return path;
}

void Asteroid::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) {
      QImage image(":/images/asteroid.png");
      painter->drawImage(QRectF(0,0,width,height), image);
}

