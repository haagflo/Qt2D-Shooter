#include "shotdouble.h"


//!  Implementation von ShotStrategy -> Zweifach Schuss.
/*!
  Erzeugt gleichzeitig zwei Schüsse.
  Einen am linken oberen Eck und einen am rechten oberen Eck des Raumschiffs.
*/
ShotDouble::ShotDouble():ShotStrategy()
{
}

ShotDouble::ShotDouble(QGraphicsItem *shut):ShotStrategy(shut)
{
}

void ShotDouble::shoot()
{
    if(lastShot.elapsed() >= reloadSpeed){
        lastShot.start();
        Shot *shot = new Shot(shuttle->rotation(), shotSpeed*2);
        shot->setPos(shuttle->mapToParent(shuttle->boundingRect().topLeft()));
        shuttle->scene()->addItem(shot);

        Shot *shot2 = new Shot(shuttle->rotation(), shotSpeed*2);
        shot2->setPos(shuttle->mapToParent(shuttle->boundingRect().topRight()));
        shuttle->scene()->addItem(shot2);
    }
}

