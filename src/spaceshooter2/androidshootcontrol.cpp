#include "androidshootcontrol.h"

AndroidShootControl::AndroidShootControl(Shuttle *shuttle) : m_shuttle(shuttle), width(100), height(100)
{
    setFlag(QGraphicsItem::ItemIsFocusable);
    setAcceptTouchEvents(true);
}

bool AndroidShootControl::sceneEvent(QEvent *e){
    switch(e->type()){
    case QEvent::TouchBegin:
        m_shuttle->setKeyPressed(Qt::Key_Space);
        break;
    case QEvent::TouchUpdate:
        break;
    case QEvent::TouchEnd:
        m_shuttle->setKeyReleased(Qt::Key_Space);
        break;
    default:
        return false;
        break;
    }
    return true;
}

QRectF AndroidShootControl::boundingRect() const
{
    return QRectF(0, 0, width, height);
}


void AndroidShootControl::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setPen(QPen(Qt::white, 0));
    painter->drawRect(boundingRect());
    painter->drawText(boundingRect(), Qt::AlignCenter, "shoot");
}
