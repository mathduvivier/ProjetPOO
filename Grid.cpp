#include "Grid.h"
using namespace std;

Grid::Grid(int height, int width, const vector<vector<int>>& GridMat)
    : height(height), width(width),
      GridCells(height, vector<Cell*>(width))//Matrice de cellules
{
    for (int j = 0; j < height; j++) {
        for (int i = 0; i < width; i++) {

            switch (GridMat[j][i]) {

            case 0: // cellule morte
                GridCells[j][i] = new Cell(new DeadState());
                break;

            case 1: // cellule vivante
                GridCells[j][i] = new Cell(new AliveState());
                break;

            case 2: // obstacle
                GridCells[j][i] = new Cell(new Obstacle());
                break;

            default:
                cout << "Erreur: type de cellule inconnu." << endl;
                GridCells[j][i] = new Cell(new DeadState());
                break;
            }
        }
    }
}

Grid::~Grid()
{
    for (int j = 0; j < height; j++) //libère la mémoire
        for (int i = 0; i < width; i++)
            delete GridCells[j][i];
}

// Grille torique et cellules obstacles évitées
int Grid::calcCellNeighbors(int x, int y)
{
    static int dx[8] = {-1,-1,-1,0,0,1,1,1};
    static int dy[8] = {-1,0,1,-1,1,-1,0,1};

    int count = 0;

    for (int k = 0; k < 8; k++) { //parcourt tous les voisins

        int nx = (x + dx[k] + width) % width; // torique vertical
        int ny = (y + dy[k] + height)  % height;  // torique horizontal

        Cell* neighbor = GridCells[nx][ny];

        // si obstacle, on ignore
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

            // Obstacles inchangés
            if (c->getSymbol() == '#') {
                newGrid[x][y] = new Cell(new Obstacle());
                continue;
            }

            int n = calcCellNeighbors(x, y);

            if (c->isAlive()) {
                if (n == 2 || n == 3) // survit
                    newGrid[x][y] = new Cell(new AliveState());
                else                // meurt
                    newGrid[x][y] = new Cell(new DeadState());
            }
            else {
                if (n == 3)         // naissance
                    newGrid[x][y] = new Cell(new AliveState());
                else                // reste morte
                    newGrid[x][y] = new Cell(new DeadState());
            }
        }
    }

    GridCells = newGrid;
}


void Grid::display()
{
    for (int x = 0; x < height; x++) {
        for (int y = 0; y < width; y++) {
            cout << GridCells[x][y]->getSymbol();
        }
        cout << endl;
    }
}
