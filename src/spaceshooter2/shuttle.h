#ifndef SHUTTLE_H
#define SHUTTLE_H

#include <QGraphicsItem>


class Shuttle : public QGraphicsItem
{
public:
    Shuttle();

    QRectF boundingRect() const Q_DECL_OVERRIDE;
    QPainterPath shape() const Q_DECL_OVERRIDE;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) Q_DECL_OVERRIDE;


protected:
    void advance(int step) Q_DECL_OVERRIDE;
    void keyPressEvent(QKeyEvent *event) Q_DECL_OVERRIDE;
    void keyReleaseEvent(QKeyEvent *event) Q_DECL_OVERRIDE;

private:
    int speed;
    QMap<int, bool> keys;

signals:

public slots:
};

#endif // SHUTTLE_H
