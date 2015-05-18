#ifndef VIEW_H
#define VIEW_H

#include <QDesktopWidget>
#include <QGraphicsView>
#include <QApplication>
#include <QMouseEvent>
#include <QDebug>

#include "point.h"
#include "line.h"

class View : public QGraphicsView
{
    Q_OBJECT
public:

    View();
    ~View();

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

signals:
    void click(QMouseEvent *event);
public slots:
     void clearPoints(QKeyEvent *event);
private:

     line *axys_x;
     line *axys_y;
     QGraphicsScene *scene;
};

#endif // VIEW_H
