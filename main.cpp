#include "jeu.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    sf::RenderWindow window(sf::VideoMode(640, 400), "SpaceInvaders");
    window.setKeyRepeatEnabled(false);
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);

    sf::Texture texturesprites;
    if (!texturesprites.loadFromFile("sprites.png")) {
        std::cerr << "Fichier sprites.png introuvable.\n";
        return 1;
    }

    sf::Sprite sinvader(texturesprites, sf::IntRect(0,0,11,8));
    sf::Sprite sjoueur(texturesprites, sf::IntRect(11,0,9,8));
    sinvader.setScale(2,2);
    sjoueur.setScale(2,2);

    jeu j;
    // Populate the game with invaders
    for (unsigned int y = 0; y < 4; ++y) {
        for (unsigned int i = 0; i < 10; ++i) {
            j.ajouter(invader(position(i*20,20+y*20), 10+i*20, 320-10*20+i*20, direction::droite));
        }
    }

    int invaderShotCooldown = 0;
    const int invaderShotFrequency = 50;

    while (window.isOpen()) {
        invaderShotCooldown++;

            if (invaderShotCooldown >= invaderShotFrequency) {
                j.tir_invader();
                invaderShotCooldown = 0; // Réinitialisez le compteur
            }

        j.tourdejeu();

        if (j.projectilecollisionjoueur()) {
            sf::Font font;
               if (font.loadFromFile("(HUNF___.TTF")) { // Ensure the font file name is correct
                   sf::Text message("Vous avez perdu !", font, 30);
                   message.setFillColor(sf::Color::Red);
                   message.setPosition(120, 150); // Position the message where you want

                   window.clear();
                   window.draw(message);
                   window.display();

                   sf::sleep(sf::seconds(5));

                   window.close(); 
               }
        }

        if(j.invaders().empty()){
            sf::Font font;
            if (font.loadFromFile("(HUNF___.TTF")) { 
                sf::Text message("Vous avez gagner !", font, 30);
                message.setFillColor(sf::Color::Green);
                message.setPosition(120, 150); 

                // Clear the window, draw the message, and then display it
                window.clear();
                window.draw(message);
                window.display();

                sf::sleep(sf::seconds(3));

                window.close(); 
            }
        }

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Left)
                    j.directionjoueur(direction::gauche);
                else if (event.key.code == sf::Keyboard::Right)
                    j.directionjoueur(direction::droite);
                else if (event.key.code == sf::Keyboard::Space)
                    j.tirjoueur();
            }
        }

        window.clear(sf::Color::Black);

        for (const auto &i : j.invaders()) {
            sinvader.setPosition(static_cast<float>(i.pos().x()) * 2, static_cast<float>(i.pos().y()) * 2);
            window.draw(sinvader);
        }

        sf::RectangleShape rprojInv(sf::Vector2f(2,2)); // Size of the projectile rectangle
        rprojInv.setFillColor(sf::Color::Red); // Color of the invader's projectile
        for (const auto &proj : j.projectilesinv()) {
            rprojInv.setPosition(proj.pos().x() * 2, proj.pos().y() * 2);
            window.draw(rprojInv);
        }

        sf::RectangleShape rproj(sf::Vector2f(2,2));
        rproj.setFillColor(sf::Color::Yellow); // Color of the player's projectile
        for (const auto &proj : j.projectiles()) {
            rproj.setPosition(proj.pos().x() * 2, proj.pos().y() * 2);
            window.draw(rproj);
        }

        sjoueur.setScale(static_cast<float>(j.Joueur().tai().w()) / 9 * 2, 2.0);
        sjoueur.setPosition(static_cast<float>(j.Joueur().pos().x()) * 2, static_cast<float>(j.Joueur().pos().y()) * 2);
        window.draw(sjoueur);

        window.display();
    }

    return 0; 
}
