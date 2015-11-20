#include "asteroidshooter.h"


AsteroidShooter::AsteroidShooter(int x, int y, int ang, int spd) :
x(x), y(y), angle(ang), speed(spd) {

}

Asteroid* AsteroidShooter::generateAsteroid() {
    Asteroid *a = new Asteroid(angle, speed);
    a->setPos(this->x, this->y);
    return a;
}
