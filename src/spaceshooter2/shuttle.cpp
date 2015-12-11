#include "shuttle.h"
#include "shotsingle.h"
#include "shotdouble.h"

Shuttle::Shuttle() : speed(10)
{
    width = 40;
    height = 50;
    life = 3;
    // needed to get KeyEvents
    setFlag(QGraphicsItem::ItemIsFocusable);
    setShotStrategy(new ShotSingle(this));
    setData(classTypeKey, shuttle);
}


// called by GraphicsScene to draw the object
void Shuttle::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    QImage image(":/images/shuttle6.png");
    painter->drawImage(QRectF(0,0,width,height), image);
    painter->setPen(QPen(Qt::green, 0));
    painter->drawText(boundingRect(), Qt::AlignCenter, QString::number(life));
}


// solution to execute an uninterrupted keyboard input:
void Shuttle::keyPressEvent(QKeyEvent *event){

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

        deleteIfCollidesWith(asteroid);
        itemCollisionHandling();
}



void Shuttle::itemCollisionHandling(){

     for(int i = 0; i < collidingItems().size(); i++){
        if(collidingItems()[i]->data(classTypeKey) == item){
             setShotStrategy(new ShotDouble(this));
        }
     }
}

