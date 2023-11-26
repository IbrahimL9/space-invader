#pragma once
#include "objet_actif.h"



class joueur:public objet_actif{


private:
    taille _taille;

public:
    joueur(position const&p,taille t,coordonee const &min,coordonee const &max,direction d);
    void malus();
    void bonus();
    bool contientposition(position const &p) const override;
    taille const& tai() const;
    char typeobjet() const override;

};
