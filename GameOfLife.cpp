#include "GameOfLife.h"
#include <iostream>
#include <SFML/System.hpp>
using namespace std;

GameOfLife::GameOfLife(const Grid& initialGrid)
    : grid(initialGrid), iteration(0)
{}

GameOfLife::~GameOfLife()
{}

void GameOfLife::display() const
{
    grid.display();
}

void GameOfLife::step()
{
    grid.update();
    iteration++;
    std::cout << "Iteration " << iteration << std::endl;
}

// MODE CONSOLE
void GameOfLife::runConsole(int steps, const File& fichier)
{
    for (int i = 0; i < steps; i++) {

        // créer le fichier iteration_i.txt
        fichier.writeIteration(grid.getMatrix(), i);

        // mise à jour
        grid.update();
	iteration++;
    }
}

// MODE GRAPHIC (SFML)
void GameOfLife::runGraphical(GraphicalInterface& interface)
{
    while (interface.isOpen()) {
        interface.pollEvents();

        interface.displayGrid(grid);   // affiche UNE SEULE matrice
        sf::sleep(sf::seconds(2)); // tempo entre matrices

        step();  // passe à la matrice suivante
    }
}
