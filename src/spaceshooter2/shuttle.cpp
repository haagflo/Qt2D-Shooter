#include "shuttle.h"
#include "shotsingle.h"
#include "shotdouble.h"

Shuttle::Shuttle() : speed(10)
{
    //Wird benötigt um KeyEvents zu erhalten!
    setFlag(QGraphicsItem::ItemIsFocusable);
    setShotStrategy(new ShotSingle(this));
}

//Dieses Rechteck wird verwendet um Herauszufinden
//welcher Bereich von der GraphicsScene neu gezeichnet werden muss.
QRectF Shuttle::boundingRect() const
{
    return QRectF(0, 0, width, height);
}

//Dieses Shape wird zur Kollisionskontrolle verwendet!
QPainterPath Shuttle::shape() const
{
    QPainterPath path;
    path.addRect(0,0, width, height);
    return path;
}

//Wird von GraphicsScene aufgerufen um das Objekt zu zeichnen
void Shuttle::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    QImage image(":/images/shuttle6.png");
    painter->drawImage(QRectF(0,0,width,height), image);
}


//Lösung um Keyboard Inputs ohne einmaligem "Stop" auszuführen:
//https://forum.qt.io/topic/28327/big-issue-with-qt-key-inputs-for-gaming/4
//http://doc.qt.io/qt-5.5/eventsandfilters.html
void Shuttle::keyPressEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_D){
        setShotStrategy(new ShotDouble(this));
    }
    if(event->key() == Qt::Key_S){
        setShotStrategy(new ShotSingle(this));
    }
    //TODO: Remove ;) Or keep it just for Fun.
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

        //wird benötigt um um das Zentrum des Rechtecks zu Rotieren
        //(Standard mäßig wird an linker oberer Ecke rotiert..)
        setTransformOriginPoint(QPoint(30,30));

        //Handling der verschiedenen KeyEvents
        if (keys[Qt::Key_Left]) {
            setRotation(qRound(rotation() - speed) % 360);
        }
        if (keys[Qt::Key_Right]) {
            setRotation(qRound(rotation() + speed) % 360);
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
