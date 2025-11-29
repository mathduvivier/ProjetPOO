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

            /* ----- OBSTACLES DÉSACTIVÉS -----
            case 2:
                GridCells[row][col] = new Cell(new Obstacle());
                break;
            ---------------------------------- */

//            default:
//                cout << "Erreur: type inconnu" << endl;
  //              GridCells[row][col] = new Cell(new DeadState());
    //            break;
	default:
	    cout << "Erreur: type inconnu, valeur = " << GridMat[row][col]
	         << " en (" << row << "," << col << ")" << endl;
	    GridCells[row][col] = new Cell(new DeadState());
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

            char symbol = other.GridCells[row][col]->getSymbol();

            switch (symbol)
            {
            case '1':   // cellule vivante
                GridCells[row][col] = new Cell(new AliveState());
                break;

            case '0':   // cellule morte
                GridCells[row][col] = new Cell(new DeadState());
                break;

 //           case '#':   // obstacle (si tu le réactives un jour)
 //               GridCells[row][col] = new Cell(new Obstacle());
 //               break;

            default:
                std::cout << "Erreur: symbole inconnu '" << symbol
                          << "' en (" << row << "," << col << ")\n";
                GridCells[row][col] = new Cell(new DeadState());
                break;
            }
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

        /* ----- OBSTACLES DÉSACTIVÉS -----
        if (neighbor->getSymbol() == '#')
            continue;
        ---------------------------------- */

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

            /* ----- OBSTACLES DÉSACTIVÉS -----
            if (c->getSymbol() == '#') {
                newGrid[row][col] = new Cell(new Obstacle());
                continue;
            }
            ---------------------------------- */

            int n = calcCellNeighbors(row, col);

            if (c->isAlive()) {
                if (n < 2 || n > 3)
                    newGrid[row][col] = new Cell(new DeadState());
                else
                    newGrid[row][col] = new Cell(new AliveState());
            }
            else {
                if (n == 3)
                    newGrid[row][col] = new Cell(new AliveState());
                else
                    newGrid[row][col] = new Cell(new DeadState());
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

            if (GridCells[row][col]->isAlive())
                mat[row][col] = 1;
            else
                mat[row][col] = 0;
        }
    }

    return mat;
}
