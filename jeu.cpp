#include "jeu.h"
#include <cstdlib>
#include <ctime>

jeu::jeu():_joueur(position(144,180),taille(9,8),10,310,direction::stop){}

bool jeu::ajouter(const projectile &p)
{
    for(std::list<projectile>::iterator it = _projectiles.begin(); it != _projectiles.end(); ++it){
        if (it->pos().x()==p.pos().x() && it->pos().y()==p.pos().y())
        {
            return false;
        }
    }
    _projectiles.push_front(p);
    return true;
}

void jeu::ajouter(const invader &i)
{
    _invaders.push_front(i);
}

const joueur &jeu::Joueur() const
{
    return _joueur;
}

const std::list <invader> &jeu::invaders() const
{
    return _invaders;
}

const std::list<projectile> &jeu::projectiles() const
{
    return _projectiles;
}

void jeu::tirjoueur()
{
    projectile p(position(_joueur.pos().x()+_joueur.tai().w()/2,_joueur.pos().y()-1));
    ajouter(p);
}


void jeu::tir_invader() {
    bool invaderShot = false;
    for (auto &inv : _invaders) {
        if (rand() % 10 == 0) { // Some chance for each invader to shoot
            position p (position(inv.pos().x() + inv.tai().w() / 2, inv.pos().y() + inv.tai().h()));
            projectile new_projectile(p);
            _projectilesinv.push_back(new_projectile);
            invaderShot = true; // An invader has shot
        }
    }

    if (!invaderShot) { // If no invader has shot yet, force one to shoot
        auto &inv = *_invaders.begin(); // Just pick the first one for simplicity
        position p (position(inv.pos().x() + inv.tai().w() / 2, inv.pos().y() + inv.tai().h()));
        projectile new_projectile(p);
        _projectilesinv.push_back(new_projectile);
    }
}




void jeu::afficher(std::ostream &s) const
{
    s << "Invaders:";
    for(const auto& invader : _invaders){
        invader.sortieflux(s);
    }

    s << "Projectiles:";
    for(const auto& projectile: _projectiles){
        projectile.sortieflux(s);
    }

    s << "Joueur:";
    _joueur.sortieflux(s);
}


std::list<projectile> const & jeu::projectilesinv() const
{
    return _projectilesinv;
}

void jeu::projectiledisparition()
{
    for (auto it = _projectiles.begin(); it != _projectiles.end();) {
            if (it->pos().y() == 0) {
                it = _projectiles.erase(it);
            } else {
                ++it;
            }
        }
}

void jeu::projectilecollision()
{
    for (auto j = _invaders.begin(); j != _invaders.end();){
        bool supp=false;
        for (auto it = _projectiles.begin(); it != _projectiles.end();){
               if(j->contientposition(it->pos())){
                  it =_projectiles.erase(it);
                   supp=true;
               }
               else ++it;
        }
        if(supp) j=_invaders.erase(j);
        else ++j;
    }
}

bool jeu::projectilecollisionjoueur()
{
        for (auto it = _projectilesinv.begin(); it != _projectilesinv.end();++it) {
            if(_joueur.contientposition(it->pos())) {

               return true;
            }
        }
        return false;
}


void jeu::tourdejeu()
{
    for( auto & invader : _invaders){
        invader.appliquerdeplacement();
    }

    for(auto & projectile: _projectiles){
        projectile.appliquerdeplacement();
    }

    for(auto & projectile: _projectilesinv){
        projectile.appliquerdeplacement_inv();
    }

    _joueur.appliquerdeplacement();
    projectiledisparition();
    projectilecollision();

}

void jeu::directionjoueur(const direction &d)
{
    _joueur.setdir(d);
}



