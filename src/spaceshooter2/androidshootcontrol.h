#ifndef ANDROIDCONTROL_H
#define ANDROIDCONTROL_H

#include <QGraphicsItem>
#include <QTouchEvent>
#include <QPainter>
#include "shuttle.h"

class AndroidShootControl : public QGraphicsItem
{
public:
    AndroidShootControl(Shuttle* shuttle);

    QRectF boundingRect() const Q_DECL_OVERRIDE;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) Q_DECL_OVERRIDE;
protected:
    bool sceneEvent(QEvent *e) Q_DECL_OVERRIDE;

private:
    Shuttle* m_shuttle;
    int width;
    int height;

};

#endif // ANDROIDCONTROL_H
