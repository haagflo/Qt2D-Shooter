#ifndef ITEM_H
#define ITEM_H

#include "collidable.h"


class Item : public Collidable
{
public:

    Item();
    ~Item() {}

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) Q_DECL_OVERRIDE;
protected:

    void advance(int step) Q_DECL_OVERRIDE;

};

#endif

