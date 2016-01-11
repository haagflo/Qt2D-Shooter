#ifndef ANDROIDROTATIONCONTROL_H
#define ANDROIDROTATIONCONTROL_H

#include <QGraphicsItem>
#include <QTouchEvent>
#include <QPainter>
#include "shuttle.h"
#include <math.h>
#include <QtMath>
#include <QList>

class AndroidRotationControl : public QGraphicsItem
{
public:
    AndroidRotationControl(Shuttle* shuttle);

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

#endif // ANDROIDROTATIONCONTROL_H
