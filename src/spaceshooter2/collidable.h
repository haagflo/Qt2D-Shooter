#ifndef COLLIDABLE_H
#define COLLIDABLE_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>

#include "constants.h"

class Collidable : public QGraphicsItem
{
public:
    Collidable();

    QRectF boundingRect() const Q_DECL_OVERRIDE;
    QPainterPath shape() const Q_DECL_OVERRIDE;

    void deleteIfCollidesWith(int datatype);    
    void deleteIfCollidesWith(int datatype, int datatype2);

protected:
    qreal life = 1;
    int width;
    int height;

signals:

public slots:
};

#endif // COLLIDABLE_H
