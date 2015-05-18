#ifndef COORDINATES_H
#define COORDINATES_H

#include <QDesktopWidget>
#include <QGraphicsView>
#include <QApplication>
#include <QPushButton>
#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QSize>

/*
 * Somente bibliotecas do sistema ficam com <>
 * as criadas por nós são envolvidas por aspas duplas ""
 */
#include "view.h"

class coordinates : public QWidget
{
    Q_OBJECT

public:
    coordinates(QWidget *parent = 0);
    ~coordinates();

    QLabel *coordinatesLabel;
    QPushButton *button;
    View *view;

public slots:
    void updateLabel(QMouseEvent *event);    
private:

    QSize screenSize;

};

#endif // COORDINATES_H
