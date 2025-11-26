#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H

#include "Grid.h"

class GameOfLife {

private:
    Grid grid;
    int iteration;

public:
    GameOfLife(const Grid& initialGrid);
    ~GameOfLife();

    void display() const;
    void step();
    void run(int steps);
};

#endif
