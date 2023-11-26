#include "taille.h"


taille::taille(unsigned int largeur, unsigned int hauteur)
    :_largeur(largeur),_hauteur(hauteur){}

const unsigned int &taille::w() const
{
    return _largeur;
}

void taille::setw(unsigned int largeur)
{
    _largeur=largeur;
}

const unsigned int &taille::h() const
{
    return _hauteur;
}
