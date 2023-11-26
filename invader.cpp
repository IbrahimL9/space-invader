#include "invader.h"



invader::invader(const position &p, const coordonee &min, const coordonee &max, direction d)
    :objet_actif(p,min,max,d),_taille(taille(11,8)){}

bool invader::contientposition(const position &p) const
{
    return  (p.x() >= objet::pos().x()) and (p.x() <= objet::pos().x()+_taille.w())
            && (p.y() >= objet::pos().y()) and (p.y() <= objet::pos().y()+_taille.h()) ;
}

char invader::typeobjet() const
{
    return 'I';
}

void invader::appliquerdeplacement()
{
      objet_actif::appliquerdeplacement();
        if (dir() == direction::droite && pos().x() == xmax()) {
            setdir(direction::gauche);
            setpos(position(pos().x(), pos().y() + 1));
        } else if (dir() == direction::gauche && pos().x() == xmin()) {
            setdir(direction::droite);
            setpos(position(pos().x(), pos().y() + 1));
        }
}

const taille &invader::tai()const
{
    return _taille;
}
