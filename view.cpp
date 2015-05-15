#include "view.h"

View::View()
{

}

View::~View()
{

}

void View::mousePressEvent(QMouseEvent *event){
    qDebug() << "test";
    qDebug() <<"x:"<< event->x() <<"y:"<< event->y();
    clicado(event);
}


