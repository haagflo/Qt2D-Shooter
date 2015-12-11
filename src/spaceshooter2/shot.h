#ifndef SHOT_H
#define SHOT_H

#include "linearmovingitems.h"

class Shot : public LinearMovingItems
{
public:
    Shot();
    Shot(qreal rot, qreal spd);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) Q_DECL_OVERRIDE;
protected:
    void advance(int step) Q_DECL_OVERRIDE;

};

#endif // SHOT_H
