#pragma once
#include "objet.h"



enum class direction{stop,droite,gauche};

class objet_actif : public objet{


private:
    coordonee _xmin;
    coordonee _xmax;
    direction _direction;

public:
    objet_actif(position const &p,coordonee const &xmin,coordonee const &xmax,direction d);
    coordonee const &xmin() const;
    coordonee const &xmax() const;
    direction const &dir()const;
    void setdir(direction const &d);
    virtual bool contientposition(position const &p) const=0;
    void appliquerdeplacement() override;

};
