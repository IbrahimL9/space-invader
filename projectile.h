#pragma once
#include "objet.h"


class projectile: public objet{

private:
    taille _taille;
public:
    projectile(position const &p);
    char typeobjet() const override;
    void appliquerdeplacement() override;
    void appliquerdeplacement_inv();

};
