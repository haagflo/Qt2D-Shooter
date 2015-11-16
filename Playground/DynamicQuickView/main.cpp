#include <QGuiApplication>
#include <QQuickView>
#include <QQmlComponent>
#include <QQuickItem>
#include <QQmlProperty>
#include <QQmlEngine>
#include <QQmlApplicationEngine>

#include "logger.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    //    If you want to use an engine, this shows how to get an UI Element!:

    //    QQmlApplicationEngine engine;
    //    engine.load(QUrl(QStringLiteral("qrc:/game.qml")));

    //    QObject root = engine.rootObjects().first();
    //    QObject element = root.findChild("element");
    //    element.setProperty("color","red");


    //Creating Objects from Qml in C++ with QQuickView
    //http://stackoverflow.com/questions/14092319/create-qml-element-in-c


    QQuickView view;
    //Background
    view.setResizeMode(QQuickView::SizeRootObjectToView);
    view.setSource(QUrl("qrc:///game.qml"));

    //Spaceshuttle
    QQmlComponent component(view.engine(), QUrl("qrc:///shuttle.qml"));
    QObject *shuttle = component.create();
    //Components are only drawn if parent is somehow related to the root view
    QQmlProperty::write(shuttle, "parent", QVariant::fromValue<QObject*>(view.rootObject()));

    //some sample "Astroids" - ( wrong Image ;) )
    QVector<QObject*> astroids(0);

    for(int i = 0; i < 5; i++){
        QQmlComponent fireballComponent(view.engine(), QUrl("qrc:///fireball.qml"));
        astroids.append(fireballComponent.create());
        QQmlProperty::write(astroids[i], "parent", QVariant::fromValue<QObject*>(view.rootObject()));
        QQmlProperty::write(astroids[i], "x", i*50);
        QQmlProperty::write(astroids[i], "y", i*50);
    }

    //QQmlEngine::setObjectOwnership(object, QQmlEngine::CppOwnership);

    qDebug() << shuttle->property("id").toString();

    Logger logger;
    logger.setQObject(shuttle);
    QObject::connect(shuttle, SIGNAL(xChanged()), &logger, SLOT(showCoordinates()));

    view.show();

    return app.exec();
}

