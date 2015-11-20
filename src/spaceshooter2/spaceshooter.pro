QT += core gui widgets

TARGET = spaceshooter
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    asteroidshooter.cpp \
    asteroid.cpp \
    shuttle.cpp

HEADERS += \
    asteroidshooter.h \
    asteroid.h \
    shuttle.h

RESOURCES += qml.qrc

