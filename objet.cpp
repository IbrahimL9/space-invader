#include "objet.h"



objet::objet(const position &p):_position(p){}

const position &objet::pos() const
{
    return _position;
}

void objet::setpos(const position &position)
{
    _position=position;
}


void objet::sortieflux(std::ostream &s) const
{
    s << typeobjet() <<" "<<_position.tostring()<<std::endl;
}
