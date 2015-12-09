
#include "item.h"

Item::Item(){
    setData(classType, item);
}

QRectF Item::boundingRect() const {
    return QRectF(0, 0, width, height);
}

QPainterPath Item::shape() const {
    QPainterPath path;
    path.addRect(0,0, width, height);
    return path;
}

void Item::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) {
      QImage image(":/images/item_feature.png");
      painter->drawImage(QRectF(0,0,width,height), image);
}

