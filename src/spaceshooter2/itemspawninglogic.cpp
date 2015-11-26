#include "itemspawninglogic.h"

ItemSpawningLogic::ItemSpawningLogic(QGraphicsScene* scene) : scene(scene) {
    // at the beginning no feature item exists
    ItemExisting = false;
}

void ItemSpawningLogic::tick2() {
    if(ItemExisting == true) {

        printf("ItemExisting = %i\n",ItemExisting);

        spawnCountdown -= 1;

        // the feature item shall be deleted after a given time
        if(spawnCountdown <= 0){
                removeItemFromRandomShooter();
        }
    }

    else {
        // create a feature item after a random number of clock ticks
        int randomcreation = rand() % 10;

        printf("randomcreation=%i\n",randomcreation);

        if(randomcreation == 0) {
            createItem();
            resetSpawnCountdown();
        }
    }
}

void ItemSpawningLogic::createItem() {
    // generate random x,y coordinates for dropping the feature item there
    int randomx = rand() % 500 - 250;
    int randomy = rand() % 500 - 250;

    printf("randomx=%i\n",randomx);
    printf("randomy=%i\n",randomy);

    // add the feature item to the scene
    Item* i = new Item();
    this->i = i;
    i->setPos(randomx, randomy);
    scene->addItem(i);

    ItemExisting = true;
}

void ItemSpawningLogic::resetSpawnCountdown() {
    // set the existing time of the next dropped feature item
    int randomcountdown = rand() % 3 + 5;

    printf("randomcountdown = %i\n",randomcountdown);

    spawnCountdown = randomcountdown;
}

void ItemSpawningLogic::removeItemFromRandomShooter() {

    //delete the existing feature item from the scene
    scene->removeItem(i);
    ItemExisting = false;
}

