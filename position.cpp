#include "position.h"





position::position(coordonee const &x, coordonee const &y):_x(x),_y(y){}

const coordonee &position::x() const
{
    return _x;
}

const coordonee &position::y() const
{
    return _y;
}

void position::setX(const coordonee &x)
{
    _x = x;
}

void position::setY(const coordonee &y)
{
    _y = y;
}

std::string position::tostring() const
{
    return "("+std::to_string(_x)+","+std::to_string(_y)+")";
}

bool position::egale(const position &p) const
{
    return _x==p.x() && _y==p.y();
}

bool position::differente(const position &p) const
{
    return _x!=p.x() || _y!=p.y();
}
