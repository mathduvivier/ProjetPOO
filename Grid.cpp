#include "Grid.h"
using namespace std;

Grid::Grid(int height, int width, const vector<vector<int>>& GridMat)
    : height(height), width(width),
      GridCells(height, vector<Cell*>(width))

{
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {

            switch (GridMat[row][col]) {

            case 0:
                GridCells[row][col] = new Cell(new DeadState());
                break;

            case 1:
                GridCells[row][col] = new Cell(new AliveState());
                break;

            case 2:
                GridCells[row][col] = new Cell(new AliveObstacleState());
                break;

            case 3:
                GridCells[row][col] = new Cell(new DeadObstacleState());
                break;

	    default:
	    cout << "Erreur: type inconnu, valeur = " << GridMat[row][col]
	         << " en (" << row << "," << col << ")" << endl;
	    break;

            }
        }
    }
}

Grid::Grid(const Grid& other)
    : height(other.height),
      width(other.width),
      GridCells(height, std::vector<Cell*>(width))
{
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
		bool CellAlive;
		bool CellObstacle;
		CellAlive = other.GridCells[row][col]->isAlive();
		CellObstacle = other.GridCells[row][col]->isObstacle();

		if (!CellAlive && !CellObstacle)
	                GridCells[row][col] = new Cell(new DeadState());

		else if (CellAlive && !CellObstacle)
	                GridCells[row][col] = new Cell(new AliveState());

		else if (CellAlive && CellObstacle)
                	GridCells[row][col] = new Cell(new AliveObstacleState());

		else if (!CellAlive && CellObstacle)
	                GridCells[row][col] = new Cell(new DeadObstacleState());

		else
		{
			cout << "Erreur: type inconnu, "
            		<< " en (" << row << "," << col << ")" << endl;
		}

          /*  char symbol = other.GridCells[row][col]->getSymbol();

            switch (symbol)
            {
            case '1':   // cellule vivante
                GridCells[row][col] = new Cell(new AliveState());
                break;

            case '0':   // cellule morte
                GridCells[row][col] = new Cell(new DeadState());
                break;

            case '2':   // obstacle
                GridCells[row][col] = new Cell(new Obstacle());
                break;

            default:
                std::cout << "Erreur: symbole inconnu '" << symbol
                          << "' en (" << row << "," << col << ")\n";
                GridCells[row][col] = new Cell(new DeadState());
                break;
            }*/
        }
    }
}

Grid::~Grid()
{
    for (int row = 0; row < height; row++)
        for (int col = 0; col < width; col++)
            delete GridCells[row][col];
}



int Grid::calcCellNeighbors(int row, int col)
{
    static int dx[8] = {-1,-1,-1,0,0,1,1,1};
    static int dy[8] = {-1,0,1,-1,1,-1,0,1};

    int count = 0;

    for (int k = 0; k < 8; k++) {

        int nrow = (row + dx[k] + height) % height;
        int ncol = (col + dy[k] + width)  % width;

        Cell* neighbor = GridCells[nrow][ncol];


        if (neighbor->isAlive())
            count++;
    }

    return count;
}

void Grid::update()
{
    vector<vector<Cell*>> newGrid(height, vector<Cell*>(width));

    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {

            Cell* c = GridCells[row][col];
            //if (c->getSymbol() == '2') {
            //    newGrid[row][col] = new Cell(new Obstacle());
            //    continue;
            //}

            int n = calcCellNeighbors(row, col);
	    if (!c->isObstacle()){
        	if (c->isAlive()) {
        		if (n < 2 || n > 3)
        	            newGrid[row][col] = new Cell(new DeadState());
        	        else
        	            newGrid[row][col] = new Cell(new AliveState());
        	} else {
                	if (n == 3)
                	    newGrid[row][col] = new Cell(new AliveState());
                	else
                	    newGrid[row][col] = new Cell(new DeadState());
		}
	     } else {
             	if (c->isAlive())
               		newGrid[row][col] = new Cell(new AliveObstacleState());
                else
                        newGrid[row][col] = new Cell(new DeadObstacleState());
             }
       	}
    }

    for (int r = 0; r < height; r++)
        for (int c = 0; c < width; c++)
            delete GridCells[r][c];

    GridCells = newGrid;
}

void Grid::display() const
{
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            cout << GridCells[row][col]->getSymbol();
        }
        cout << endl;
    }
}
std::vector<std::vector<int>> Grid::getMatrix() const
{
    std::vector<std::vector<int>> mat(height, std::vector<int>(width));

    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {

	char s = GridCells[row][col]->getSymbol();

            if (s == '1')          // vivante
                mat[row][col] = 1;

            else if (s == '0')     // morte
                mat[row][col] = 0;

            else if (s == '2')     // obstacle vivante
                mat[row][col] = 2;

            else if (s == '3')     // obstacle morte
                mat[row][col] = 3;

            else
                mat[row][col] = 0; // valeur par défaut
        }
    }

    return mat;
}
