#include "GameOfLife.h"
#include <iostream>
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
}

// MODE CONSOLE
void GameOfLife::runConsole(int steps)
{
    for (int i = 0; i < steps; i++) {
        display();
        cout << endl; // ligne vide
        step();
    }
}

// MODE GRAPHIC (SFML)
void GameOfLife::runGraphical(GraphicalInterface& interface)
{
    while (interface.isOpen()) {
        interface.pollEvents();
        interface.displayGrid(grid);
        step();   // met à jour la grille en continu
    }
}
