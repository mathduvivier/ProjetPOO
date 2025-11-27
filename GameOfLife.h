#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H

#include "Grid.h"
#include "GraphicalInterface.h"

class GameOfLife {

private:
    Grid grid;
    int iteration;

public:
    GameOfLife(const Grid& initialGrid);
    ~GameOfLife();

    void display() const;
    void step();

    // MODE CONSOLE
    void runConsole(int steps);

    // MODE GRAPHIQUE
    void runGraphical(GraphicalInterface& interface);

    const Grid& getGrid() const { return grid; }
};

#endif
