#include "logger.h"
#include <QDebug>

Logger::Logger(QObject *parent) : QObject(parent)
{

}

void Logger::setQObject(QObject *qobject)
{
    object = qobject;
}

void Logger::showCoordinates()
{
    qDebug() << "X: " << object->property("x").toInt();
    qDebug() << "Y: " << object->property("y").toInt();
}

