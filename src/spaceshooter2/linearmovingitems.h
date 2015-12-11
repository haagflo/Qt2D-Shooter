#ifndef LINEARMOVINGITEMS_H
#define LINEARMOVINGITEMS_H


#include <math.h>
#include <QtMath>

#include "collidable.h"

class LinearMovingItems : public Collidable
{
public:
    LinearMovingItems();
    LinearMovingItems(qreal rot, qreal spd);

protected:
    void advance(int step) Q_DECL_OVERRIDE;
    void deleteIfOutlier();
    void deleteIfCollides();

private:
    qreal speed;
};

#endif // LINEARMOVINGITEMS_H
