#ifndef ROUNDRESTARTLOGIC
#define ROUNDRESTARTLOGIC

#include <QObject>
#include <iostream>
#include <cstdlib>

#include "shuttle.h"
#include "itemspawninglogic.h"
#include "asteroid.h"

class RoundRestartLogic : public QObject {
    Q_OBJECT

public:
    RoundRestartLogic(Shuttle* shuttle, ItemSpawningLogic*, QGraphicsScene* scene);
    ~RoundRestartLogic() {}

private:
    void deleteAllSceneAsteroids();

public slots:
    void tick();

private:
    Shuttle* shuttlePtr;
    QGraphicsScene* scenePtr;
    ItemSpawningLogic* itemSpawningPtr;
    bool restartPending = false;
    int ticksUntilRestart = 90;

};


#endif // ROUNDRESTARTLOGIC

