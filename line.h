#ifndef LINE_H
#define LINE_H
#include <QObject>
#include <QGraphicsLineItem>

class line : public QObject, public QGraphicsLineItem
{
    Q_OBJECT

public:
    line(int x1, int y1, int x2, int y2);
    ~line();
};

#endif // LINE_H
