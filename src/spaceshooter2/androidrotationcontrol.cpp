#include "androidrotationcontrol.h"
#include <QDebug>


AndroidRotationControl::AndroidRotationControl(Shuttle *shuttle) : m_shuttle(shuttle), width(200), height(200)
{
    setFlag(QGraphicsItem::ItemIsFocusable);
    setAcceptTouchEvents(true);
}

bool AndroidRotationControl::sceneEvent(QEvent *e){
    switch(e->type()){
    case QEvent::TouchBegin:
    case QEvent::TouchUpdate:
    case QEvent::TouchEnd:{
        QTouchEvent *touchEvent = static_cast<QTouchEvent *>(e);
        QList<QTouchEvent::TouchPoint> points = touchEvent->touchPoints();
        m_shuttle->setRotation((qAtan2(points.first().pos().y(),points.first().pos().x()) * 180/M_PI) + 90);
        break;
    }
    default:
        return false;
        break;
    }
    return true;
}

QRectF AndroidRotationControl::boundingRect() const
{
    return QRectF(width*-0.5, height*-0.5, width, height);
}


void AndroidRotationControl::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    QPointF center(0,0);
    painter->setPen(QPen(Qt::white, 0));
    painter->drawEllipse(center, width/2, height/2);
    painter->drawEllipse(center, width/8, height/8);
    painter->rotate(45);
    painter->drawRect(-25, -25, 50, 50);
}
