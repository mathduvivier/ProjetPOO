#include "Grid.h"
#include <string>
using namespace std;

Grid::Grid(int height,int width,vector<vector<int>>& GridMat){
    for (j=0; j<height; j++){
        for (i=0; i<width; i++){
		switch(GridMat[j][i]) {
		  case 0:
		    GridCells[j][i]=new DeadCell;
		    break;
		  case 1:
		    GridCells[j][i]=new AliveCell;
		    break;
		  case 2:
                    GridCells[j][i]=new DeadObstaclCell;
                    break;
		  case 3:
                    GridCells[j][i]=new AliveObstaclCell;
                    break;
		  default:
		    cout<<"Error: undefined Cell type."<<endl;
		}
	}
    }
}
	int get_height();
	int get_width();
	vector<int> get_vector();
