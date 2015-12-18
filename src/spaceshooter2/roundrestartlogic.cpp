#include "roundrestartlogic.h"

RoundRestartLogic::RoundRestartLogic(Shuttle* shuttle, ItemSpawningLogic* itemSpawning, QGraphicsScene* scene) {
    this->shuttlePtr = shuttle;
    this->itemSpawningPtr = itemSpawning;
    this->scenePtr = scene;
}

void RoundRestartLogic::tick() {
    if(shuttlePtr->isAlive()) {
        return;
    }

    if(ticksUntilRestart-- <= 0) {
        ticksUntilRestart = 90;
        Shuttle *shuttle = new Shuttle(itemSpawningPtr);
        scenePtr->addItem(shuttle);
        scenePtr->setFocusItem(shuttle);
        this->shuttlePtr = shuttle;
        deleteAllSceneAsteroids();
    }
}

void RoundRestartLogic::deleteAllSceneAsteroids() {
    QList<QGraphicsItem*> sceneItems = scenePtr->items();
    for(int i = sceneItems.length()-1; i > -1; i--) {
        if(typeid(*(sceneItems[i])) == typeid(Asteroid)) {
            std::cout << "Found item to be of type " << typeid(*(sceneItems[i])).name() << std::endl;
            //((Asteroid)(*sceneItems[i])).deleteSelf();
            //TODO ^ can't cast sceneItems to asteroid
        }
    }
}
