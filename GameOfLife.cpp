#include "GameOfLife.h"
#include <iostream>

using namespace std;

GameOfLife::GameOfLife(int height, int width, const vector<vector<int>>& mat)
{
    grid = new Grid(height, width, mat);
    generation = 0;
}

GameOfLife::~GameOfLife()
{
    delete grid;
}

void GameOfLife::display() const
{
    cout << "Generation : " << generation << endl;
    grid->display();
}

void GameOfLife::step()
{
    grid->update();
    generation++;
}

void GameOfLife::run(int steps)
{
    for (int i = 0; i < steps; i++) {
        display();
        step();
    }
}
