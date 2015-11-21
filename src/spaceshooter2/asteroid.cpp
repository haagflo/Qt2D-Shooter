#include "asteroid.h"

Asteroid::Asteroid(){
}

Asteroid::Asteroid(qreal rot, qreal spd) :LinearMovingItems(rot, spd)
{
}

QRectF Asteroid::boundingRect() const {
    return QRectF(0, 0, 30, 30);
}

QPainterPath Asteroid::shape() const {
    QPainterPath path;
    path.addRect(0,0, 30, 30);
    return path;
}

void Asteroid::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) {
//    painter->setBrush(scene()->collidingItems(this).isEmpty() ? Qt::darkYellow : Qt::red);
//    painter->drawEllipse(0, 0, 30, 30);

      QImage image(":/images/fireball.png");
      painter->drawImage(QRectF(0,0,30,30), image);
}

