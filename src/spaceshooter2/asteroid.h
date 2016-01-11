#ifndef ASTROID_H
#define ASTROID_H

#include "linearmovingitems.h"

class Asteroid : public LinearMovingItems
{
public:

    Asteroid();
    Asteroid(qreal rot, qreal spd);
    Asteroid(int x, int y, qreal rot, qreal spd);


    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) Q_DECL_OVERRIDE;
protected:
    void advance(int step) Q_DECL_OVERRIDE;
    bool head;
};

#endif
