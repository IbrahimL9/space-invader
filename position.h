#pragma once
#include <iostream>



using coordonee=unsigned int;

class position{


private:
    coordonee _x;
    coordonee _y;

public:
    position(coordonee const &x,coordonee const &y);
    coordonee const &x() const;
    coordonee const &y() const;
    void setX(const coordonee &x);
    void setY(const coordonee &y);
    std::string tostring() const;
    bool egale(position const &p) const;
    bool differente(position const &p) const;

};
