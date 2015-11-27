#include "shotsingle.h"

//!  Implementation of ShotStrategy -> single shot
/*!
  creation of shot in the centre of the shuttle
  (TODO: set to middle top edge of shuttle)
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

