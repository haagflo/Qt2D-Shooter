#ifndef SHOTSTRATEGY_H
#define SHOTSTRATEGY_H

#include <QTime>

#include "shot.h"

class ShotStrategy
{
public:

    ShotStrategy();
    //Referenz auf Shuttle wird benötigt um Startposition des Schusses festzulegen
    ShotStrategy(QGraphicsItem* shut);

    //Just for FUN ;)
    void increaseReloadSpeed(int speed){reloadSpeed-speed > 50 ? reloadSpeed -= speed: reloadSpeed +=0;}
    void increaseShotSpeed(int speed){shotSpeed+speed > 5 ? shotSpeed += speed: shotSpeed += 0;}

    //Erzeugt ein neues Shot-Objekt und fügt es der Scene hinzu
    virtual void shoot() = 0 Q_DECL_OVERRIDE;
    virtual ~ShotStrategy(){}

protected:
    QTime lastShot;
    QGraphicsItem* shuttle;
    //Geschwindigkeit mit welcher nach einander Schüsse abgefeuert werden können
    int reloadSpeed;
    //Geschoss Fluggeschwindigkeit
    int shotSpeed;

};

#endif // SHOTSTRATEGY_H
