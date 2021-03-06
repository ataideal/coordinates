#include "view.h"

View::View():QGraphicsView()
{
    setMouseTracking(true);

    scene = new QGraphicsScene();
    pointList = new QList<point*>();

    axys_x = NULL;
    axys_y = NULL;

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
        pointList->append(currentPoint);
        scene->addItem(currentPoint);
    }

    emit click(event);
}

void View::mouseMoveEvent(QMouseEvent *event){
    if(!axys_x)
    {
        axys_x = new line(0, scene->height()/2, scene->width(), scene->height()/2);
        scene->addItem(axys_x);
        qDebug() << "Eixo x criado";
    }
    if(!axys_y)
    {
        axys_y = new line(scene->width()/2, 0, scene->width()/2, scene->height());
        scene->addItem(axys_y);
        qDebug() << "Eixo y criado";
    }

    scene->removeItem(axys_x);
    scene->removeItem(axys_y);

    axys_x->setLine(0,event->y()+10, scene->width(), event->y()+10);
    axys_y->setLine(event->x()+10,0, event->x()+10, scene->width());


    scene->addItem(axys_x);
    scene->addItem(axys_y);
}


void View::clearPoints()
{
    foreach (point *point, *pointList) {
         scene->removeItem(point);
    }
}
