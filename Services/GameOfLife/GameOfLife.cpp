#include "GameOfLife.h"
#include <iostream>
#include <SFML/System.hpp>
#include <sstream>
using namespace std;

// Constructeur : initialise la grille et met l’itération à zéro
GameOfLife::GameOfLife(const Grid& initialGrid)
    : grid(initialGrid), iteration(0)
{}

// Destructeur (pas d’action particulière ici)
GameOfLife::~GameOfLife()
{}

// Affiche la grille courante dans la console
void GameOfLife::display() const
{
    grid.display();
}

// Effectue une étape du jeu : mise à jour + incrémentation du compteur
void GameOfLife::step()
{
    Grid oldGrid = grid;
    grid.update();
    iteration++;
}

// ========================= MODE CONSOLE =========================
void GameOfLife::runConsole(int steps, const File& fichier)
{
    ostringstream filename;

    for (int i = 0; i < steps; i++) {

        // Construire le nom du fichier iteration_i.txt
        filename << "iteration_" << i << ".txt";

        // Écrire l’état actuel de la grille dans ce fichier
        fichier.WriteFile(filename.str(), grid);

        // Mise à jour de la grille pour l’itération suivante
        step();

        // Réinitialise le nom pour la prochaine boucle
        filename.str("");
    }
}

// ========================= MODE GRAPHIQUE (SFML) =========================
void GameOfLife::runGraphical(int steps, GraphicalInterface& interface)
{
    // Affiche la grille initiale
    interface.displayGrid(grid);

    int current = 0;

    // Boucle d’affichage tant que la fenêtre est ouverte et que
    // le nombre d’itérations demandé n’est pas atteint
    while (interface.isOpen() && current < steps) {

        // Gestion des événements SFML (clavier, fermeture, etc.)
        interface.pollEvents();

        // Affiche la grille actuelle
        interface.displayGrid(grid);

        // Petite pause pour rendre l’évolution visible
        sf::sleep(sf::seconds(1));

        // Passe à l’état suivant
        step();
        current++;
    }
}
