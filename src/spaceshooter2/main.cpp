#include <QtWidgets>
#include <math.h>

#include "asteroid.h"
#include "asteroidspawninglogic.h"
#include "shuttle.h"
#include "qvector.h"
#include "item.h"
#include "itemspawninglogic.h"
#include "roundrestartlogic.h"
#include "androidshootcontrol.h"
#include "androidspeedcontrol.h"
#include "androidrotationcontrol.h"

//#define WINDOW_WIDTH 600
//#define WINDOW_HEIGHT 600

int main(int argc, char **argv) {

    QApplication app(argc, argv);

    int window_height = app.screens().at(0)->availableSize().height();
    int window_width = app.screens().at(0)->availableSize().width();

    QGraphicsScene scene;

    scene.setSceneRect(-window_width/2,-window_height/2,window_width,window_height);
    scene.setItemIndexMethod(QGraphicsScene::NoIndex);

    //-----------------------------------------------------------
    //  ITEM SPAWNING
    //-----------------------------------------------------------
    ItemSpawningLogic itemSpawningLogic(&scene);


    //-----------------------------------------------------------
    //  SHUTTLE SETUP
    //-----------------------------------------------------------
    Shuttle *shuttle = new Shuttle(&itemSpawningLogic);

    scene.addItem(shuttle);
    scene.setFocusItem(shuttle);

    RoundRestartLogic roundRestartLogic(shuttle, &itemSpawningLogic, &scene);


    //-----------------------------------------------------------
    //  ANDROID CONTROLS
    //-----------------------------------------------------------
    if(QSysInfo::productType() == "android"){
        AndroidShootControl *androidShootControl = new AndroidShootControl(shuttle);
        scene.addItem(androidShootControl);
        androidShootControl->setPos(400,120);

        AndroidSpeedControl *androidSpeedControl = new AndroidSpeedControl(shuttle);
        scene.addItem(androidSpeedControl);
        androidSpeedControl->setPos(500,200);

        AndroidRotationControl *androidRotationControl = new AndroidRotationControl(shuttle);
        scene.addItem(androidRotationControl);
        androidRotationControl->setPos(-500,200);
    }

    //-----------------------------------------------------------
    //  ASTEROID SPAWNING
    //-----------------------------------------------------------
    AsteroidShooter shooter1(-300, -300, 135, 5, &scene);
    AsteroidShooter shooter2(-300, -80, 95, 3, &scene);
    AsteroidShooter shooter3(-300, 50, 80, 3, &scene);
    AsteroidShooter shooter4(-120, 300, 50, 3, &scene);
    AsteroidShooter shooter5(120, 300, 350, 2, &scene);
    AsteroidShooter shooter6(300, 40, 300, 4, &scene);
    AsteroidShooter shooter7(300, -180, 220, 3, &scene);

    QVector<AsteroidShooter> shooters;
    shooters.append(shooter1);
    shooters.append(shooter2);
    shooters.append(shooter3);
    shooters.append(shooter4);
    shooters.append(shooter5);
    shooters.append(shooter6);
    shooters.append(shooter7);

    AsteroidSpawningLogic asteroidSpawningLogic(30, shooters);

    //-----------------------------------------------------------
    //  TICK SIGNALS
    //-----------------------------------------------------------
    QTimer timer; //Game loop timer (30 FPS)
    QObject::connect(&timer, SIGNAL(timeout()), &scene, SLOT(advance()));
    QObject::connect(&timer, SIGNAL(timeout()), &asteroidSpawningLogic, SLOT(tick()));
    QObject::connect(&timer, SIGNAL(timeout()), &roundRestartLogic, SLOT(tick()));
    timer.start(1000 / 33);

    QTimer timer2; //Item spawning
    QObject::connect(&timer2, SIGNAL(timeout()), &itemSpawningLogic, SLOT(tick2()));
    timer2.start(1000);

    QTimer difficultyTimer; //
    QObject::connect(&difficultyTimer, SIGNAL(timeout()), &asteroidSpawningLogic, SLOT(increaseDifficulty()));
    difficultyTimer.start(10000);

    //-----------------------------------------------------------
    //  GRAPHICS SETUP
    //-----------------------------------------------------------
    QGraphicsView view(&scene);
    view.setRenderHint(QPainter::Antialiasing);
    view.setBackgroundBrush(QPixmap(":/images/backgroundSpace.png"));
    view.setFixedSize(window_width,window_height);
    view.setCacheMode(QGraphicsView::CacheBackground);
    view.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view.setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    view.setWindowTitle(QT_TRANSLATE_NOOP(QGraphicsView, "Qt2D-SpaceShooter"));
    view.show();

    return app.exec();
}
