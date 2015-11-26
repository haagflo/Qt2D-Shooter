#ifndef ITEMSPAWNINGLOGIC
#define ITEMSPAWNINGLOGIC

#include <QObject>
#include <iostream>
#include "item.h"
#include <cstdlib>

class ItemSpawningLogic : public QObject {
    Q_OBJECT

public:
    ItemSpawningLogic(QGraphicsScene* scene);
    ~ItemSpawningLogic() {}

    void createItem();

private:
    void resetSpawnCountdown();
    void spawnItemFromRandomShooter();
    void removeItemFromRandomShooter();

public slots:
    void tick2();

private:
    int spawnCountdown;
    bool ItemExisting;
    QGraphicsScene* scene;
    Item* i;
};

#endif // ITEMSPAWNINGLOGIC


