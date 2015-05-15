#include "view.h"

View::View():QGraphicsView()
{
    setMouseTracking(true);

    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    points = new QList<point *>();
    scene= new QGraphicsScene();
    setScene(scene);
}

View::~View()
{

}

void View::mousePressEvent(QMouseEvent *event){
    if(event->button() == Qt::LeftButton)
    {
        point *currentPoint = new point(event->x() - 10, event->y() - 10);
        scene->addItem(currentPoint);
    }
    emit click(event);
}

void View::mouseMoveEvent(QMouseEvent *event){

}

QList<point *> *View::getPointsList()
{
    return points;
}

