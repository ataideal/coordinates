#ifndef POINT_H
#define POINT_H

#include <QGraphicsRectItem>
#include <QObject>

class point : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    point(qreal x, qreal y);
    ~point();
};

#endif // POINT_H
