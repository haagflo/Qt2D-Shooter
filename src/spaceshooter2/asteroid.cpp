#include "asteroid.h"
#include <iostream>
#include <stdio.h>
#include <QGraphicsScene>
#include <QPainter>
#include <QStyleOption>
#include <math.h>
#include <QtMath>


Asteroid::Asteroid() : color(255,0,255) {
    setRotation(0);
    speed = 5;
}

Asteroid::Asteroid(qreal rot, qreal spd) :  speed(spd) {
    setRotation(rot);
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

void Asteroid::advance(int step) {
    if (!step)
        return;

    qreal nextX = x() + qSin(rotation() * M_PI/180) * speed;
    qreal nextY = y() - qCos(rotation() * M_PI/180) * speed;

    setPos(QPointF(nextX, nextY));
    deleteIfOutlier();
}

void Asteroid::deleteIfOutlier() {
    if(pos().y() < -300 || pos().x() < -300 ||
       pos().y() > 300 || pos().x() > 300 ){
        scene()->removeItem(this);
    }
}
