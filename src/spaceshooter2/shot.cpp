#include "shot.h"

//!  Ein Schuss des Raumschiffs
/*!
  TODO: Kann noch um Zerstörungskraft erweitert werden. Dann kann diese Klasse als Elternklasse
  für unterschiedliche Munition verwendet werden. (z.B. Schwacher Schuss braucht zwei Treffer um
  Asteorid zu zerstören)
*/
Shot::Shot() : LinearMovingItems()
{
}

Shot::Shot(qreal rot, qreal spd) : LinearMovingItems(rot, spd)
{
}

QRectF Shot::boundingRect() const {
    return QRectF(0, 0, width, height);
}

QPainterPath Shot::shape() const {
    QPainterPath path;
    path.addRect(0, 0, width, height);
    return path;
}

void Shot::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) {
    QImage image(":/images/shot2.png");
    painter->drawImage(QRectF(0,0,width,height), image);
}
