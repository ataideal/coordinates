#include "point.h"

point::point(qreal x, qreal y)
{
    this->setRect(0,0,20,20);
    this->setX(x);
    this->setY(y);
}

point::~point()
{

}

