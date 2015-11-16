#ifndef LOGGER_H
#define LOGGER_H

#include <QObject>

class Logger : public QObject
{
    Q_OBJECT
public:
    explicit Logger(QObject *parent = 0);
    void setQObject(QObject *object);

signals:

public slots:
    void showCoordinates();
private:
    QObject *object;
};

#endif // LOGGER_H
