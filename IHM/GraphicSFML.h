#ifndef GRAPHICSFML_H
#define GRAPHICSFML_H

#include <SFML/Graphics.hpp>
#include "GraphicalInterface.h"
#include "Grid.h"

// Implémentation SFML de l’interface graphique du Jeu de la Vie.
// Cette classe affiche la grille dans une fenêtre SFML.
class GraphicSFML : public GraphicalInterface {

private:
    int cellSize;            // Taille en pixels d'une cellule
    sf::RenderWindow window; // Fenêtre SFML où la grille sera dessinée

public:
    // Constructeur : initialise la fenêtre et la taille d’une cellule
    GraphicSFML(int cellSize, int width, int height);

    // Affiche la grille dans la fenêtre
    void displayGrid(const Grid& grid) override;

    // Indique si la fenêtre est encore ouverte
    bool isOpen() const override { return window.isOpen(); }

    // Gère les événements (fermeture de fenêtre, etc.)
    void pollEvents() override;
};

#endif
