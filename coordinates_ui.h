#ifndef COORDINATES_UI_H
#define COORDINATES_UI_H

#include <QGraphicsView>
#include <QWidget>
#include <QLayout>
class coordinates_ui {

public:

    static void setupUi(QWidget *window){
        window->setWindowTitle("Coordinates");
        QHBoxLayout *windowLayout = new QHBoxLayout();
        window->setLayout(windowLayout);
    }

};

#endif // COORDINATES_UI_H

