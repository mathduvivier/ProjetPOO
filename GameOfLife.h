#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H

#include <vector>
#include "Grid.h"

class GameOfLife {

private:
    Grid* grid;      // pointeur vers la grille
    int generation;  // numéro de génération

public:
    GameOfLife(int height, int width, const std::vector<std::vector<int>>& mat);
    ~GameOfLife();

    void display() const;  // affiche la grille
    void step();           // calcule une génération
    void run(int steps);   // lance plusieurs générations
};

#endif
