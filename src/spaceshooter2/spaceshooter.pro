QT += core gui widgets

TARGET = spaceshooter
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    asteroidshooter.cpp \
    asteroid.cpp \
    shuttle.cpp \
    shot.cpp \
    linearmovingitems.cpp \
    shotsingle.cpp \
    shotdouble.cpp \
    shotstrategy.cpp \
    asteroidspawninglogic.cpp \
    item.cpp \
    itemshooter.cpp \
    itemspawninglogic.cpp

HEADERS += \
    asteroidshooter.h \
    asteroid.h \
    shuttle.h \
    shot.h \
    linearmovingitems.h \
    shotsingle.h \
    shotstrategy.h \
    shotdouble.h \
    asteroidspawninglogic.h \
    item.h \
    itemshooter.h \
    itemspawninglogic.h

RESOURCES += qml.qrc

