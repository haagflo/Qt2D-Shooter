#ifndef SHOTSINGLE_H
#define SHOTSINGLE_H

#include "shotstrategy.h"

class ShotSingle : public ShotStrategy
{
public:
    ShotSingle();
    ShotSingle(QGraphicsItem *shut);

    void shoot();

signals:

public slots:
};

#endif // SHOTSINGLE_H
