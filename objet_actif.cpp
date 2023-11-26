#include "objet_actif.h"



objet_actif::objet_actif(const position &p, const coordonee &xmin, const coordonee &xmax,direction d)
    :objet(p),_xmin(xmin),_xmax(xmax),_direction(d){}


coordonee const &objet_actif::xmin() const
{
    return _xmin;
}


coordonee const &objet_actif::xmax() const
{
    return _xmax;
}

const direction &objet_actif::dir() const
{
    return _direction;
}

void objet_actif::setdir(direction const &d)
{
    _direction=d;
}

void objet_actif::appliquerdeplacement()
{
    switch (_direction) {
        case direction::stop:
            break;
        case direction::droite:
            if(objet::pos().x()<_xmax)
                objet::setpos(position(objet::pos().x()+1,objet::pos().y()));
        break;
        case direction::gauche:
            if(objet::pos().x()>_xmin)
                objet::setpos(position(objet::pos().x()-1,objet::pos().y()));

        break;

    }
}

