#include "coordinates.h"
#include "coordinates_ui.h"

coordinates::coordinates(QWidget *parent)
    : QWidget(parent)
{
    coordinates_ui::setupUi(this);

    screenSize = QApplication::desktop()->size();

    this->setMinimumSize(screenSize);
    this->setMaximumSize(screenSize);

    button = new QPushButton("Clear Points");
    coordinatesLabel = new QLabel("X: Y:");

    /*
     * Nunca deixar nome de variáveis como sideBarLayout, button, label
     * Sempre dar nomes que sejam fáceis de identificar o componente
     *
     * Para evitar de ficar chamando o atributo QApplication::desktop()->size(),
     * Criei uma variavel local que armazenará isso. Aumentaremos assim a legibilidade
     * do código!
     */


    /*
     * No problema em que nos encontramos, o ideal é criar um QWidget
     * para botar o QVBoxLayout dentro, pois assim poderemos limitar o
     * o tamanho do layout
     */


    QWidget *sideBar = new QWidget(this);
    sideBar->setLayout(new QVBoxLayout(sideBar));

    sideBar->setMinimumSize(screenSize.width()/5, screenSize.height());
    sideBar->setMaximumSize(screenSize.width()/5, screenSize.height());

    sideBar->layout()->addWidget(button);
    sideBar->layout()->addWidget(coordinatesLabel);

    this->layout()->addWidget(sideBar);

    view = new View();
    this->layout()->addWidget(view);
    connect(view,SIGNAL(click(QMouseEvent*)),this,SLOT(updateLabel(QMouseEvent*)));
    connect(button,SIGNAL(clicked()),view,SLOT(clearPoints()));
}

coordinates::~coordinates()
{

}

void coordinates::updateLabel(QMouseEvent *event){
    coordinatesLabel->setText("X: "+ QString::number(event->x()) +"Y: "+ QString::number(event->y()));
}
