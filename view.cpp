#include "view.h"

View::View():QGraphicsView()
{
    setMouseTracking(true);

    points = new QList<point *>();
    scene = new QGraphicsScene();

    /*
     * Tem que limitar o tamanho do view e o do scene (BRUNO)
     *
     * Como definimos que o painel é 1/5
     * A tela deve ser 4/5
     */
    QSize screenSize = QApplication::desktop()->size();

    this->setMaximumSize(4*screenSize.width()/5, screenSize.height());

    scene->setSceneRect(0,0,4*screenSize.width()/5, screenSize.height());

    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    setScene(scene);
}

View::~View()
{

}

void View::mousePressEvent(QMouseEvent *event){

    if(event->button() == Qt::LeftButton)
    {
        point *currentPoint = new point(event->x(), event->y());
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

