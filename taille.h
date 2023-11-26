#pragma once



class taille{

private:
    unsigned int _largeur;
    unsigned int _hauteur;

public:
    taille(unsigned int largeur,unsigned int hauteur);


    unsigned int const &w() const;
    void setw(unsigned int largeur);
    unsigned int const &h() const;
};

