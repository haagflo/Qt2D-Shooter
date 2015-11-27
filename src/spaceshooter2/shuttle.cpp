#include "shuttle.h"
#include "shotsingle.h"
#include "shotdouble.h"

Shuttle::Shuttle() : speed(10)
{
    // needed to get KeyEvents
    setFlag(QGraphicsItem::ItemIsFocusable);
    setShotStrategy(new ShotSingle(this));
}

// this rectangle is used to find out which area of the GraphicsScene has to be redrawn
QRectF Shuttle::boundingRect() const
{
    return QRectF(0, 0, width, height);
}

// this shape is used for collision control
QPainterPath Shuttle::shape() const
{
    QPainterPath path;
    path.addRect(0,0, width, height);
    return path;
}

// called by GraphicsScene to draw the object
void Shuttle::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    QImage image(":/images/shuttle6.png");
    painter->drawImage(QRectF(0,0,width,height), image);
}


// solution to execute an uninterrupted keyboard input:
void Shuttle::keyPressEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_D){
        setShotStrategy(new ShotDouble(this));
    }
    if(event->key() == Qt::Key_S){
        setShotStrategy(new ShotSingle(this));
    }
    // TODO: future use for special items
    if(event->key() == Qt::Key_Plus){
        shotstrategy->increaseReloadSpeed(10);
    }
    if(event->key() == Qt::Key_Minus){
        shotstrategy->increaseReloadSpeed(-10);
    }
    if(event->key() == Qt::Key_O){
        shotstrategy->increaseShotSpeed(2);
    }
    if(event->key() == Qt::Key_L){
        shotstrategy->increaseShotSpeed(-2);
    }
    keys[event->key()] = true;
}

void Shuttle::keyReleaseEvent(QKeyEvent *event){
    keys[event->key()] = false;
}

void Shuttle::advance(int step) {
     if (!step)
        return;

        // necessary to rotate around the centre of the rectangle
        // (default: rotation around the top left corner)
        setTransformOriginPoint(QPoint(width/2,height/2));

        // handling of different KeyEvents
        if (keys[Qt::Key_Left]) {
            setRotation(qRound(rotation() - turnspeed) % 360);
        }
        if (keys[Qt::Key_Right]) {
            setRotation(qRound(rotation() + turnspeed) % 360);
        }
        if (keys[Qt::Key_Up]) {
            qreal nextX = x() + qSin(rotation() * M_PI/180) * speed;
            qreal nextY = y() - qCos(rotation() * M_PI/180) * speed;

            setPos(QPointF(nextX, nextY));
        }
        if (keys[Qt::Key_Down]) {
            qreal nextX = x() - qSin(rotation() * M_PI/180) * speed;
            qreal nextY = y() + qCos(rotation() * M_PI/180) * speed;

            setPos(QPointF(nextX, nextY));
        }
        if(keys[Qt::Key_Space]){
            shotstrategy->shoot();
        }
}
