/****************************************************************************
**
** Copyright (C) 2015 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include <QtWidgets>
#include <math.h>

#include "asteroid.h"
#include "asteroidspawninglogic.h"
#include "shuttle.h"
#include "qvector.h"
#include "itemshooter.h"

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 600

int main(int argc, char **argv) {

    QApplication app(argc, argv);
    qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));

    QGraphicsScene scene;
    scene.setSceneRect(-WINDOW_WIDTH/2,-WINDOW_HEIGHT/2,WINDOW_WIDTH,WINDOW_HEIGHT);
    scene.setItemIndexMethod(QGraphicsScene::NoIndex);

    //-----------------------------------------------------------
    //  SHUTTLE SETUP
    //-----------------------------------------------------------
    Shuttle *shuttle = new Shuttle();
    scene.addItem(shuttle);
    scene.setFocusItem(shuttle);

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
    //  ITEM SPAWNING
    //-----------------------------------------------------------
    ItemShooter item1(50, 50, &scene);


    //-----------------------------------------------------------
    //  TICK SIGNALS
    //-----------------------------------------------------------
    QTimer timer;
    QObject::connect(&timer, SIGNAL(timeout()), &scene, SLOT(advance()));
    QObject::connect(&timer, SIGNAL(timeout()), &asteroidSpawningLogic, SLOT(tick()));
    timer.start(1000 / 33);

    //-----------------------------------------------------------
    //  GRAPHICS SETUP
    //-----------------------------------------------------------
    QGraphicsView view(&scene);
    view.setRenderHint(QPainter::Antialiasing);
    view.setBackgroundBrush(QPixmap(":/images/backgroundSpace.png"));
    view.setFixedSize(WINDOW_WIDTH,WINDOW_HEIGHT);
    view.setCacheMode(QGraphicsView::CacheBackground);
    view.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //Ich glaube daher kamen die Streifen(weil außerhalb des BoundingRect nicht neugezeichnet wurde)
    view.setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    //Die Variante zeichnet dafür langsamer..
    //view.setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    view.setWindowTitle(QT_TRANSLATE_NOOP(QGraphicsView, "Qt2D-SpaceShooter"));
    view.show();

    return app.exec();
}
