#include "shuttle.h"
#include "shotsingle.h"
#include "shotdouble.h"
#include "itemspawninglogic.h"

Shuttle::Shuttle(ItemSpawningLogic* itemSpawningLogic) : speed(10)
{
    width = 40;
    height = 50;
    life = 3;
    // needed to get KeyEvents
    setFlag(QGraphicsItem::ItemIsFocusable);
    setShotStrategy(new ShotSingle(this));
    setData(classTypeKey, shuttle);

    itemSpawningLogicLocal = itemSpawningLogic;
}


// called by GraphicsScene to draw the object
void Shuttle::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    QImage image(":/images/shuttle6.png");
    painter->drawImage(QRectF(0,0,width,height), image);
    painter->setPen(QPen(Qt::green, 0));
    painter->drawText(boundingRect(), Qt::AlignCenter, QString::number(life));
}

void Shuttle::setKeyPressed(int key)
{
    keys[key] = true;
}

void Shuttle::setKeyReleased(int key)
{
    keys[key] = false;
}



// solution to execute an uninterrupted keyboard input:
void Shuttle::keyPressEvent(QKeyEvent *event){

    // TODO: future use for special items (in current Version just for testing)
    switch(event->key()){
    case Qt::Key_Plus:
        shotstrategy->increaseReloadSpeed(10);
        break;
    case Qt::Key_Minus:
        shotstrategy->increaseReloadSpeed(-10);
        break;
    case Qt::Key_O:
        shotstrategy->increaseShotSpeed(2);
        break;
    case Qt::Key_L:
        shotstrategy->increaseShotSpeed(-2);
    default:
        keys[event->key()] = true;
    }
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

    Item* Itemgetted;
    Itemgetted = itemSpawningLogicLocal->getItem();

     for(int i = 0; i < collidingItems().size(); i++){
        if(collidingItems()[i]->data(classTypeKey) == item){
            if(Itemgetted->ItemType == 0) {
                setShotStrategy(new ShotDouble(this));
            }

            else if(Itemgetted->ItemType == 1) {
                // 0.5 because function is called twice
                // when collision of shuttle with life item occurs
                life = life + 0.5;
            }
        }
    }
}
