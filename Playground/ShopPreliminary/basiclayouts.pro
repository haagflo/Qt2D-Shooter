QT += widgets

HEADERS     = dialog.h
SOURCES     = dialog.cpp \
              main.cpp

# install
target.path = /Arbeit/Projekte/_FHA_Qt_Vorlesung/git_25_11_2015/Qt2D-Shooter/Playground/ShopPreliminary

INSTALLS += target

DISTFILES += \
    items/life2.jpg \
    items/weapons1.jpg
