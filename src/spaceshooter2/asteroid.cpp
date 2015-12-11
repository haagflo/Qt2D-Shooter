#include "asteroid.h"

Asteroid::Asteroid(){
}

Asteroid::Asteroid(qreal rot, qreal spd) : LinearMovingItems(rot, spd) {
    width = 32;
    height = 32;
    life = 2;
    setData(classTypeKey, asteroid);
}

void Asteroid::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) {
      QImage image(":/images/asteroid.png");
      painter->drawImage(QRectF(0,0,width,height), image);

      painter->setPen(QPen(Qt::white, 0));
      painter->drawText(boundingRect(), Qt::AlignCenter, QString::number(life));
}

void Asteroid::advance(int step)
{
    LinearMovingItems::advance(step);
    deleteIfCollidesWith(shot, shuttle);
}



