#include "Grid.h"
using namespace std;

Grid::Grid(int height, int width, const vector<vector<int>>& GridMat)
    : height(height), width(width),
      GridCells(height, vector<Cell*>(width))
{
    for (int j = 0; j < height; j++) {
        for (int i = 0; i < width; i++) {

            switch (GridMat[j][i]) {

            case 0:
                GridCells[j][i] = new Cell(new DeadState());
                break;

            case 1:
                GridCells[j][i] = new Cell(new AliveState());
                break;

            case 2:
                GridCells[j][i] = new Cell(new Obstacle());
                break;

            default:
                cout << "Erreur: type inconnu" << endl;
                GridCells[j][i] = new Cell(new DeadState());
                break;
            }
        }
    }
}

Grid::~Grid()
{
    for (int j = 0; j < height; j++)
        for (int i = 0; i < width; i++)
            delete GridCells[j][i];
}

int Grid::calcCellNeighbors(int x, int y)
{
    static int dx[8] = {-1,-1,-1,0,0,1,1,1};
    static int dy[8] = {-1,0,1,-1,1,-1,0,1};

    int count = 0;

    for (int k = 0; k < 8; k++) {

        int nx = (x + dx[k] + height) % height;
        int ny = (y + dy[k] + width)  % width;

        Cell* neighbor = GridCells[nx][ny];

        if (neighbor->getSymbol() == '#')
            continue;

        if (neighbor->isAlive())
            count++;
    }

    return count;
}

void Grid::update()
{
    vector<vector<Cell*>> newGrid(height, vector<Cell*>(width));

    for (int x = 0; x < height; x++) {
        for (int y = 0; y < width; y++) {

            Cell* c = GridCells[x][y];

            if (c->getSymbol() == '#') {
                newGrid[x][y] = new Cell(new Obstacle());
                continue;
            }

            int n = calcCellNeighbors(x, y);

            if (c->isAlive()) {
                if (n < 2 || n > 3)
                    newGrid[x][y] = new Cell(new DeadState());
                else
                    newGrid[x][y] = new Cell(new AliveState());
            }
            else {
                if (n == 3)
                    newGrid[x][y] = new Cell(new AliveState());
                else
                    newGrid[x][y] = new Cell(new DeadState());
            }
        }
    }

    GridCells = newGrid;
}

void Grid::display() const   // <-- IMPORTANT : const ajouté !
{
    for (int x = 0; x < height; x++) {
        for (int y = 0; y < width; y++) {
            cout << GridCells[x][y]->getSymbol();
        }
        cout << endl;
    }
}
