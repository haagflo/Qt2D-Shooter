#ifndef SHOTDOUBLE_H
#define SHOTDOUBLE_H

#include "shotstrategy.h"

class ShotDouble : public ShotStrategy
{
public:
    ShotDouble();
    ShotDouble(QGraphicsItem *shut);

    void shoot();

signals:

public slots:
};

#endif // SHOTDOUBLE_H
