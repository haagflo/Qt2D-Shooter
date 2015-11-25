#ifndef SHOT_H
#define SHOT_H

#include "linearmovingitems.h"

class Shot : public LinearMovingItems
{
public:
    Shot();
    Shot(qreal rot, qreal spd);

    QRectF boundingRect() const Q_DECL_OVERRIDE;
    QPainterPath shape() const Q_DECL_OVERRIDE;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) Q_DECL_OVERRIDE;

private:
    int width = 3;
    int height = 10;
};

#endif // SHOT_H
