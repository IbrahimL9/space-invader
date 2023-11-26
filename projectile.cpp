#include "projectile.h"



projectile::projectile(const position &p):objet(p),_taille(taille(1,1)){}



char projectile::typeobjet() const
{
    return 'P';
}

void projectile::appliquerdeplacement()
{
    objet::setpos(position(objet::pos().x(),objet::pos().y()-1));
}

void projectile::appliquerdeplacement_inv()
{
    objet::setpos(position(objet::pos().x(),objet::pos().y()+1));
}


