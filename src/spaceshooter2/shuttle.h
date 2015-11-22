#ifndef SHUTTLE_H
#define SHUTTLE_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>
#include <QKeyEvent>
#include <math.h>
#include <QtMath>

#include "shotstrategy.h"

class Shuttle : public QGraphicsItem
{
public:
    Shuttle();
    void setShotStrategy(ShotStrategy *strat)  { shotstrategy = strat; }
    void shoot();

    QRectF boundingRect() const Q_DECL_OVERRIDE;
    QPainterPath shape() const Q_DECL_OVERRIDE;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) Q_DECL_OVERRIDE;



protected:
    void advance(int step) Q_DECL_OVERRIDE;
    void keyPressEvent(QKeyEvent *event) Q_DECL_OVERRIDE;
    void keyReleaseEvent(QKeyEvent *event) Q_DECL_OVERRIDE;

private:
    int speed;
    QMap<int, bool> keys;
    ShotStrategy* shotstrategy;
    int width = 40;
    int height = 50;
};

#endif // SHUTTLE_H
