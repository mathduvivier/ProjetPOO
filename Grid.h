#ifndef GRID_H
#define GRID_H
#include <string>
#include <vector>
#include "AliveCell.h"
#include "DeadCell.h"
#include "AliveObstacleCell.h"
#include "DeadObstacleCell.h"

class Grid{
private:
	int height;
	int width;
	std::vector<std::vector<Cell*>> GridCells;
public:
	Grid(int height,int width,const std::vector<std::vector<int>>& GridMat);
	~Grid();
	int get_height() const;
	int get_width() const;
	Cell* get_Cell(int row, int col) const;
};
#endif
