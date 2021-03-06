#ifndef SHUTTLE_H
#define SHUTTLE_H

#include <QKeyEvent>
#include <math.h>
#include <QtMath>

#include "shotstrategy.h"
#include "collidable.h"
#include "itemspawninglogic.h"

class Shuttle : public Collidable
{
public:
    Shuttle(ItemSpawningLogic* itemSpawningLogic);
    void setShotStrategy(ShotStrategy *strat) { shotstrategy = strat; }
    void shoot();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) Q_DECL_OVERRIDE;
    bool isAlive();
    void setKeyPressed(int key);
    void setKeyReleased(int key);

protected:
    void keyPressEvent(QKeyEvent *event) Q_DECL_OVERRIDE;
    void keyReleaseEvent(QKeyEvent *event) Q_DECL_OVERRIDE;
    void advance(int step) Q_DECL_OVERRIDE;
    void itemCollisionHandling();

private:
    int speed;
    QMap<int, bool> keys;
    ShotStrategy* shotstrategy;
    int turnspeed = 12;

    ItemSpawningLogic* itemSpawningLogicLocal;
};

#endif // SHUTTLE_H
