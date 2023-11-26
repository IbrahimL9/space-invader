#pragma once
#include "objet_actif.h"




class invader : public objet_actif{


private:
    taille _taille;

public:
    invader(position const&p,coordonee const &min,coordonee const &max,direction d);
    bool contientposition(position const &p) const override;
    char typeobjet() const override;
    void appliquerdeplacement() override;
    const taille &tai()const;
};
