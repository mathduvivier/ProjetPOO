#ifndef GRID_H
#define GRID_H

#include <vector>
#include <iostream>

#include "Cell.h"
#include "AliveState.h"
#include "DeadState.h"
#include "Obstacle.h"

class Grid {

private:
    int height;
    int width;
    std::vector<std::vector<Cell*>> GridCells;

public:
    Grid(int height, int width, const std::vector<std::vector<int>>& GridMat);
    ~Grid();

    int get_height() const { return height; }
    int get_width() const { return width; }

    Cell* get_Cell(int row, int col) const { return GridCells[row][col]; }

    int calcCellNeighbors(int x, int y);

    void update();

    void display() const;      // <-- IMPORTANT : const ajouté !
};

#endif
