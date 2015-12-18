#ifndef ASTEROIDSPAWNINGLOGIC
#define ASTEROIDSPAWNINGLOGIC

#include <QObject>
#include <iostream>
#include "asteroidshooter.h"
#include <cstdlib>

class AsteroidSpawningLogic : public QObject {
    Q_OBJECT

public:
    AsteroidSpawningLogic(int spawningTickDelta, QVector<AsteroidShooter>& shooters);
    ~AsteroidSpawningLogic() {}

private:
    void resetSpawnCountdown();
    void spawnAsteroidFromRandomShooter();
    int  getRandomShooterId();

public slots:
    void tick();
    void increaseDifficulty();

private:
    QVector<AsteroidShooter>& shooters;
    int spawningTickDelta;
    int spawnCountdown;
    int lastShootersId;
};

#endif // ASTEROIDSPAWNINGLOGIC

