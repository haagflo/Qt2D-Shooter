#include "shotsingle.h"

//!  Implementation von ShotStrategy -> Einfacher Schuss.
/*!
  Erzeugt einen Schuss in der Mitte des Raumschiffs.
  (TODO: ist noch nicht gut, muss die Mitte der oberen Kante des Raumschiffs sein..)
*/
ShotSingle::ShotSingle():ShotStrategy(){
}

ShotSingle::ShotSingle(QGraphicsItem *shut):ShotStrategy(shut) {
}

void ShotSingle::shoot()
{
    if(lastShot.elapsed() >= reloadSpeed){
        lastShot.start();
        Shot *shot = new Shot(shuttle->rotation(), shotSpeed*2);
        shot->setPos(shuttle->mapToParent(shuttle->boundingRect().center()));
        shuttle->scene()->addItem(shot);
    }

}

