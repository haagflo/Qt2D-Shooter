#include "shotdouble.h"


//!  Implementation of ShotStrategy -> double shot
/*!
  creation of two shots at same time
  one in the left top corner and one in the right top corner of the shuttle
*/

ShotDouble::ShotDouble():ShotStrategy() {
}

ShotDouble::ShotDouble(QGraphicsItem *shut):ShotStrategy(shut) {
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

