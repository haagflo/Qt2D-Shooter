#include "asteroidspawninglogic.h"

AsteroidSpawningLogic::AsteroidSpawningLogic(int spawningTickDelta, QVector<AsteroidShooter>& shooters) :
                                             shooters(shooters) {
    this->spawningTickDelta = spawningTickDelta;
    resetSpawnCountdown();
}

void AsteroidSpawningLogic::tick() {
    spawnCountdown -= 1;
    if(spawnCountdown <= 0){
        spawnAsteroidFromRandomShooter();
        resetSpawnCountdown();
    }
}

void AsteroidSpawningLogic::resetSpawnCountdown() {
    spawnCountdown = this->spawningTickDelta;
}

void AsteroidSpawningLogic::spawnAsteroidFromRandomShooter() {
    if(shooters.length() <= 0) {
        return;
    }
    int shooterId = getRandomShooterId();
    AsteroidShooter shooter = shooters.at(shooterId);
    shooter.shootAsteroid();
}

int AsteroidSpawningLogic::getRandomShooterId() {
    if(shooters.length() > 0) {
        int randomId;
        while((randomId = rand() % shooters.length()) == lastShootersId);
        lastShootersId = randomId;
        return randomId;
    }
    return -1;
}
