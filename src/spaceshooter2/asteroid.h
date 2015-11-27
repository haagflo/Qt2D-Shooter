#ifndef ASTROID_H
#define ASTROID_H

#include "linearmovingitems.h"

class Asteroid : public LinearMovingItems
{
public:

    Asteroid();
    Asteroid(qreal rot, qreal spd);
    Asteroid(int x, int y, qreal rot, qreal spd);

    QRectF boundingRect() const Q_DECL_OVERRIDE;
    QPainterPath shape() const Q_DECL_OVERRIDE;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) Q_DECL_OVERRIDE;

private:
    int width = 32;
    int height = 32;
};

#endif
