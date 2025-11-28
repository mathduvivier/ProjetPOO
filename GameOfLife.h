#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H
#include "GraphicalInterface.h"
#include "Grid.h"
#include "File.h"

class GameOfLife {
private:
    Grid grid;
    int iteration;

public:
    GameOfLife(const Grid& initialGrid);
    ~GameOfLife();

    void display() const;
    void step();

    void runConsole(int steps, const File& fichier);
    void runGraphical(GraphicalInterface& interface);
};

#endif
