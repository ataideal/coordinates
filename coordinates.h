#ifndef COORDINATES_H
#define COORDINATES_H

#include <QWidget>
#include <QSize>
#include <QLabel>
#include <QApplication>
#include <QDesktopWidget>
#include <QPushButton>
#include <QGraphicsView>
#include <QObject>

#include <view.h>

class coordinates : public QWidget
{
    Q_OBJECT

public:
    coordinates(QWidget *parent = 0);
    ~coordinates();

    QLabel *label;
    QPushButton *button;
    QSize screenSize;
    View *view;

public slots:
    void updateLabel(QMouseEvent *event);

};

#endif // COORDINATES_H
