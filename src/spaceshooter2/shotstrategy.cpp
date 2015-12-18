#include "shotstrategy.h"

ShotStrategy::ShotStrategy() {
}

ShotStrategy::ShotStrategy(QGraphicsItem *shut)
{
    shuttle = shut;
    shotSpeed = 20;
    reloadSpeed = 80;
    lastShot.start();
}
