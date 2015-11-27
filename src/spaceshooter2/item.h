#ifndef ITEM_H
#define ITEM_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>


class Item : public QGraphicsItem
{
public:

    Item();
    ~Item() {}

    QRectF boundingRect() const Q_DECL_OVERRIDE;
    QPainterPath shape() const Q_DECL_OVERRIDE;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) Q_DECL_OVERRIDE;

private:
    int width = 30;
    int height = 30;
};

#endif

