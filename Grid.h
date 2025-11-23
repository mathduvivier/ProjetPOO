#ifndef GRID_H
#define GRID_H
#include <string>
using namespace std


class Grid{
private:
	int height;
	int width;
	vector<int> Gridvector;
public:
	Grid(int height,int width,vector<int> Gridvector);
	int get_height();
	int get_width();
	vector<int> get_vector();
}
#endif
