#pragma once
#include "position.h"
#include "taille.h"


class objet{

private:
    position _position;

public:
    objet(position const &p);
    position const &pos() const;
    void setpos(const position &position);
    virtual char typeobjet() const=0;
    void sortieflux(std::ostream &s) const;
    virtual void appliquerdeplacement()=0;
};
