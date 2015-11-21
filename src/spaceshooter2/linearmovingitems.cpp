#include "linearmovingitems.h"

//!  Elternklasse für alle geradlinig bewegliche Objekte.
/*!
  Asteoriden oder Schüsse, evtl. auch Items deren Bewegung durch eine
  Geschwindigkeit und durch eine Rotationsrichtung beschrieben werden können.
*/
LinearMovingItems::LinearMovingItems()
{
    setTransformOriginPoint(boundingRect().width()/2, boundingRect().height()/2);
    setRotation(0);
    speed = 5;
}

LinearMovingItems::LinearMovingItems(qreal rot, qreal spd) :  speed(spd) {
    setRotation(rot);
}

QRectF LinearMovingItems::boundingRect() const {
    return QRectF(0, 0, 30, 30);
}

QPainterPath LinearMovingItems::shape() const {
    QPainterPath path;
    path.addRect(0,0, 30, 30);
    return path;
}

void LinearMovingItems::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) {
    QImage image(":/images/fireball.png");
    painter->drawImage(QRectF(0,0,30,30), image);
}

void LinearMovingItems::advance(int step) {
    if (!step)
        return;

    qreal nextX = x() + qSin(rotation() * M_PI/180) * speed;
    qreal nextY = y() - qCos(rotation() * M_PI/180) * speed;

    setPos(QPointF(nextX, nextY));
    deleteIfCollides();
    deleteIfOutlier();
}

void LinearMovingItems::deleteIfOutlier() {
    if(pos().y() < -300 || pos().x() < -300 ||
       pos().y() > 300 || pos().x() > 300 ){
        scene()->removeItem(this);
    }
}

void LinearMovingItems::deleteIfCollides(){
        if(!collidingItems().isEmpty()){
            //TODO: Start Animation and optimize Shapes...
            //Kollisionserkenung schlägt zu früh an, weil Grafiken größer sind als man sieht..
            //Die Bilder haben einen Alphawert für alles was außenherum liegt, (also transparent)..
            //ansonsten sollte es einfach mit dieser Zeile funktionieren:
        //    scene()->removeItem(this);
        }
}
