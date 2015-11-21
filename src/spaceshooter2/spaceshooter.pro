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
    shotstrategy.cpp

HEADERS += \
    asteroidshooter.h \
    asteroid.h \
    shuttle.h \
    shot.h \
    linearmovingitems.h \
    shotsingle.h \
    shotstrategy.h \
    shotdouble.h

RESOURCES += qml.qrc

