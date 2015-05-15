#ifndef VIEW_H
#define VIEW_H
#include <QGraphicsView>
#include <QDebug>
#include <QMouseEvent>
#include <QObject>

class View : public QGraphicsView
{
public:
    View();
    ~View();

    void mousePressEvent(QMouseEvent *event);
    void clicado(QMouseEvent *event);
};

#endif // VIEW_H
