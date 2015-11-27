#include "linearmovingitems.h"

//!  parent class for all linear moving objects
/*!
     asteroids or shots, maybe items whose movement is described via speed and orientation
*/

LinearMovingItems::LinearMovingItems() {
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
    if(pos().y() < -350 || pos().x() < -350 ||
       pos().y() > 350 || pos().x() > 350 ){
        scene()->removeItem(this);
    }
}

void LinearMovingItems::deleteIfCollides(){
        if(!collidingItems().isEmpty()){

        // TODO for collision control
        // scene()->removeItem(this);
        }
}
