#include "GameOfLife.h"
#include <iostream>

using namespace std;

GameOfLife::GameOfLife(const Grid& initialGrid)
    : grid(initialGrid), iteration(0)
{
}

GameOfLife::~GameOfLife()
{
}

void GameOfLife::display() const
{
    grid.display();
}

void GameOfLife::step()
{
    grid.update();
    iteration++;
}

void GameOfLife::run(int steps)
{
    for (int i = 0; i < steps; i++) {
        display();
        step();
    }
}
