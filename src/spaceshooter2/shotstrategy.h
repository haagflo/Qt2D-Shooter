#ifndef SHOTSTRATEGY_H
#define SHOTSTRATEGY_H

#include <QTime>

#include "shot.h"

class ShotStrategy
{
public:

    ShotStrategy();
    // reference to shuttle is necessary to set up start position of shot

    ShotStrategy(QGraphicsItem* shut);

    // for future special items
    void increaseReloadSpeed(int speed){reloadSpeed-speed > 50 ? reloadSpeed -= speed: reloadSpeed +=0;}
    void increaseShotSpeed(int speed){shotSpeed+speed > 5 ? shotSpeed += speed: shotSpeed += 0;}

    // creation of new shot object and adding to the scene
    virtual void shoot() = 0;

    virtual ~ShotStrategy(){}

protected:
    QTime lastShot;
    QGraphicsItem* shuttle;
    int reloadSpeed;
    int shotSpeed;

};

#endif // SHOTSTRATEGY_H
