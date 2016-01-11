#include "collidable.h"

Collidable::Collidable()
{
}

QRectF Collidable::boundingRect() const {
    return QRectF(0, 0, width, height);
}

QPainterPath Collidable::shape() const {
    QPainterPath path;
    path.addRect(0,0, width, height);
    return path;
}

void Collidable::deleteIfCollidesWith(int classtype)
{
    //will be deleted one frame after collision..
    //good enough? or should collision control of all items be done in main?
    if(life == 0){
        //speed = 0;
        //do animation
        scene()->removeItem(this);
    }
    if(!collidingItems().isEmpty()){
        for(int i = 0; i < collidingItems().size(); i++){
            if(collidingItems()[i]->data(classTypeKey) == classtype){
                 life -= 1;
            }
        }
    }
}

void Collidable::deleteIfCollidesWith(int classtype, int classtype2) {
    if(life <= 0){
        deleteSelf();
    }
    if(!collidingItems().isEmpty()){
        for(int i = 0; i < collidingItems().size(); i++){
            auto data = collidingItems()[i]->data(classTypeKey);
            if(data == classtype || data  == classtype2){
                 life -= 1;
            }
        }
    }
}

void Collidable::deleteSelf() {
    scene()->removeItem(this);
}
