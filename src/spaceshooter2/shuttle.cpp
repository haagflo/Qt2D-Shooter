#include "shuttle.h"

#include <QGraphicsScene>
#include <QPainter>
#include <QEvent>
#include <QKeyEvent>
#include <QWidget>
#include <math.h>
#include <QtMath>

Shuttle::Shuttle()
{
    //Wird benötigt um KeyEvents zu erhalten!
    setFlag(QGraphicsItem::ItemIsFocusable);
    speed = 10;
}

//Dieses Rechteck wird verwendet um Herauszufinden
//welcher Bereich von der GraphicsScene neu gezeichnet werden muss.
QRectF Shuttle::boundingRect() const
{
    return QRectF(0, 0, 60, 60);
}

//Dieses Shape wird zur Kollisionskontrolle verwendet!
QPainterPath Shuttle::shape() const
{
    QPainterPath path;
    path.addRect(0,0, 60, 60);
    return path;
}

//Wird von GraphicsScene aufgerufen um das Objekt zu zeichnen
void Shuttle::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    QImage image(":/images/shuttle.png");
    painter->drawImage(QRectF(0,0,60,60), image);
}

//Lösung um Keyboard Inputs ohne einmaligem "Stop" auszuführen:
//https://forum.qt.io/topic/28327/big-issue-with-qt-key-inputs-for-gaming/4
//http://doc.qt.io/qt-5.5/eventsandfilters.html
void Shuttle::keyPressEvent(QKeyEvent *event){
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
            setRotation(qRound(rotation() - 10) % 360);
        }
        if (keys[Qt::Key_Right]) {
            setRotation(qRound(rotation() + 10) % 360);
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

}
