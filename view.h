#ifndef VIEW_H
#define VIEW_H

#include <QDesktopWidget>
#include <QGraphicsView>
#include <QApplication>
#include <QMouseEvent>
#include <QDebug>

#include "point.h"

class View : public QGraphicsView
{
    Q_OBJECT
public:

    View();
    ~View();

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

    QList<point *> *getPointsList();

signals:
    void click(QMouseEvent *event);

private:

     QList<point *> *points;
     QGraphicsScene *scene;
};

#endif // VIEW_H
