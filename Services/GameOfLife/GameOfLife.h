#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H

#include "GraphicalInterface.h"
#include "Grid.h"
#include "File.h"

// Cette classe gère la logique du Jeu de la Vie.
// Elle contient une grille et gère les différentes itérations,
// en mode console ou en mode graphique.
class GameOfLife {
private:
    Grid grid;       // La grille courante du jeu
    int iteration;   // Numéro de l’itération actuelle

public:
    // Initialise le jeu avec une grille donnée
    GameOfLife(const Grid& initialGrid);

    // Destructeur (ici probablement vide)
    ~GameOfLife();

    // Affiche la grille courante (mode console)
    void display() const;

    // Effectue une seule évolution de la grille
    void step();

    // Exécute le jeu dans le mode console et écrit chaque étape dans des fichiers
    void runConsole(int steps, const File& fichier);

    // Exécute le jeu en mode graphique via une interface graphique
    void runGraphical(int steps, GraphicalInterface& interface);
};

#endif
