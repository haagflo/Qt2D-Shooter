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
    itemspawninglogic.cpp \
    collidable.cpp \
    roundrestartlogic.cpp
    collidable.cpp \
    androidrotationcontrol.cpp \
    androidshootcontrol.cpp \
    androidspeedcontrol.cpp

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
    itemspawninglogic.h \
    constants.h \
    collidable.h \
    roundrestartlogic.h\
    collidable.h \
    androidrotationcontrol.h \
    androidshootcontrol.h \
    androidspeedcontrol.h

RESOURCES += qml.qrc

DISTFILES += \
    android/AndroidManifest.xml \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/gradlew \
    android/res/values/libs.xml \
    android/build.gradle \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/gradlew.bat

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android
