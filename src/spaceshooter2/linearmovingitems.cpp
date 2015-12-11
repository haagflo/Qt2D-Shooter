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

void LinearMovingItems::advance(int step) {
    if (!step)
        return;

    qreal nextX = x() + qSin(rotation() * M_PI/180) * speed;
    qreal nextY = y() - qCos(rotation() * M_PI/180) * speed;

    setPos(QPointF(nextX, nextY));
    deleteIfOutlier();
}

void LinearMovingItems::deleteIfOutlier() {
    if(pos().y() < -350 || pos().x() < -350 ||
       pos().y() > 350 || pos().x() > 350 ){
        scene()->removeItem(this);
    }
}

