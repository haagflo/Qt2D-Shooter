#include "asteroidshooter.h"

AsteroidShooter::AsteroidShooter() {

}

AsteroidShooter::AsteroidShooter(int x, int y, int ang, int spd, QGraphicsScene* scene) :
x(x), y(y), angle(ang), speed(spd), scene(scene) {

}

void AsteroidShooter::shootAsteroid() {
    Asteroid* a = new Asteroid(angle, speed);
    a->setPos(this->x, this->y);
    scene->addItem(a);
}
