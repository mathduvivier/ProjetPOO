#ifndef GRID_H
#define GRID_H
#include <string>



class Grid{
private:
	int height;
	int width;
	std::vector<std::vector<Cell>> GridCells;
public:
	Grid(int height,int width,const vector<vector<int>>& GridMat);
	int get_height();
	int get_width();
};
#endif
