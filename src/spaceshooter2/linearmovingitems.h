#ifndef LINEARMOVINGITEMS_H
#define LINEARMOVINGITEMS_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>
#include <math.h>
#include <QtMath>
#include "constants.h"


class LinearMovingItems : public QGraphicsItem
{
public:
    LinearMovingItems();
    LinearMovingItems(qreal rot, qreal spd);

    QRectF boundingRect() const Q_DECL_OVERRIDE;
    QPainterPath shape() const Q_DECL_OVERRIDE;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) Q_DECL_OVERRIDE;

protected:
    void advance(int step) Q_DECL_OVERRIDE;
    void deleteIfOutlier();
    void deleteIfCollides();

private:
    qreal speed;
    qreal hits;
    qreal life = 1;


};

#endif // LINEARMOVINGITEMS_H
