#ifndef ASTEROIDSHOOTER
#define ASTEROIDSHOOTER

#include "asteroid.h"

class AsteroidShooter {

public:
    AsteroidShooter();
    AsteroidShooter(int xPos, int yPos, int ang, int spd, QGraphicsScene* scene);
    ~AsteroidShooter() {}

    void shootAsteroid();

private:
    int x;
    int y;
    int angle;
    int speed;
    QGraphicsScene* scene;
};

#endif
