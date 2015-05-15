#include "coordinates.h"
#include "coordinates_ui.h"

coordinates::coordinates(QWidget *parent)
    : QWidget(parent)
{
    coordinates_ui::setupUi(this);

    this->setMinimumSize(QApplication::desktop()->size());
    this->setMaximumSize(QApplication::desktop()->size());

    button = new QPushButton("Button");
    label = new QLabel("X: Y:");

    QVBoxLayout *teste = new QVBoxLayout();
    teste->addWidget(button);
    teste->addWidget(label);
    this->layout()->addItem(teste);

    this->layout()->addWidget(button);
    this->layout()->addWidget(label);

    view = new View();
    this->layout()->addWidget(view);
    connect(view,SIGNAL(clicked(QMouseEvent*)),this,SLOT(updateLabel(QMouseEvent*)));
}

coordinates::~coordinates()
{

}


void coordinates::updateLabel(QMouseEvent *event){
    qDebug() << "label";
    label->setText("x:"+ QString(event->x()) +"y:"+ QString(event->y()));
}
