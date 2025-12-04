#include "Grid.h"
using namespace std;

// Constructeur principal : crée la grille à partir d'une matrice d'entiers.
// Selon la valeur de GridMat, on crée une cellule avec un état spécifique.
Grid::Grid(int height, int width, const vector<vector<int>>& GridMat)
    : height(height), width(width),
      GridCells(height, vector<Cell*>(width))
{
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {

            switch (GridMat[row][col]) {

            case 0:
                // Cellule morte
                GridCells[row][col] = new Cell(new DeadState());
                break;

            case 1:
                // Cellule vivante
                GridCells[row][col] = new Cell(new AliveState());
                break;

            case 2:
                // Obstacle vivant
                GridCells[row][col] = new Cell(new AliveObstacleState());
                break;

            case 3:
                // Obstacle mort
                GridCells[row][col] = new Cell(new DeadObstacleState());
                break;

            default:
                // Valeur inattendue dans la matrice
                cout << "Erreur: type inconnu, valeur = " << GridMat[row][col]
                     << " en (" << row << "," << col << ")" << endl;
                break;
            }
        }
    }
}

// Constructeur de copie : recrée chaque cellule avec un nouvel objet d'état.
Grid::Grid(const Grid& other)
    : height(other.height),
      width(other.width),
      GridCells(height, std::vector<Cell*>(width))
{
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {

            bool CellAlive = other.GridCells[row][col]->isAlive();
            bool CellObstacle = other.GridCells[row][col]->isObstacle();

            // Reconstruction de l’état en fonction des booléens
            if (!CellAlive && !CellObstacle)
                GridCells[row][col] = new Cell(new DeadState());

            else if (CellAlive && !CellObstacle)
                GridCells[row][col] = new Cell(new AliveState());

            else if (CellAlive && CellObstacle)
                GridCells[row][col] = new Cell(new AliveObstacleState());

            else if (!CellAlive && CellObstacle)
                GridCells[row][col] = new Cell(new DeadObstacleState());

            else
                cout << "Erreur: type inconnu en (" << row << "," << col << ")" << endl;
        }
    }
}

// Destructeur : libère la mémoire de toutes les cellules.
Grid::~Grid()
{
    for (int row = 0; row < height; row++)
        for (int col = 0; col < width; col++)
            delete GridCells[row][col];
}

// Calcule le nombre de voisins vivants en torique (bords repliés).
int Grid::calcCellNeighbors(int row, int col)
{
    static int dx[8] = {-1,-1,-1,0,0,1,1,1};
    static int dy[8] = {-1,0,1,-1,1,-1,0,1};

    int count = 0;

    for (int k = 0; k < 8; k++) {

        int nrow = (row + dx[k] + height) % height;
        int ncol = (col + dy[k] + width)  % width;

        Cell* neighbor = GridCells[nrow][ncol];

        // On compte seulement les cellules vivantes
        if (neighbor->isAlive())
            count++;
    }

    return count;
}



// Met à jour la grille selon les règles du jeu de la vie,
// en prenant en compte les obstacles.
void Grid::update()
{
    vector<vector<Cell*>> newGrid(height, vector<Cell*>(width));

    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {

            Cell* c = GridCells[row][col];
            int n = calcCellNeighbors(row, col);

            // Si ce n'est pas un obstacle, appliquer les règles classiques
            if (!c->isObstacle()) {

                if (c->isAlive()) {
                    // Une cellule vivante meurt si <2 ou >3 voisins
                    if (n < 2 || n > 3)
                        newGrid[row][col] = new Cell(new DeadState());
                    else
                        newGrid[row][col] = new Cell(new AliveState());

                } else {
                    // Une cellule morte devient vivante si elle a 3 voisins
                    if (n == 3)
                        newGrid[row][col] = new Cell(new AliveState());
                    else
                        newGrid[row][col] = new Cell(new DeadState());
                }

            } else {
                // Pour les obstacles, l'état change seulement vivant/mort
                if (c->isAlive())
                    newGrid[row][col] = new Cell(new AliveObstacleState());
                else
                    newGrid[row][col] = new Cell(new DeadObstacleState());
            }
        }
    }

    // Libération de l'ancienne grille
    for (int r = 0; r < height; r++)
        for (int c = 0; c < width; c++)
            delete GridCells[r][c];

    // Remplacement par la nouvelle grille
    GridCells = newGrid;
}

// Affiche les symboles de chaque cellule de la grille
void Grid::display() const
{
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            cout << GridCells[row][col]->getSymbol();
        }
        cout << endl;
    }
}

// Génère une matrice d'entiers représentant l'état de chaque cellule
std::vector<std::vector<int>> Grid::getMatrix() const
{
    std::vector<std::vector<int>> mat(height, std::vector<int>(width));

    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {

            char s = GridCells[row][col]->getSymbol();

            // Conversion du symbole vers un entier
            if (s == '1')
                mat[row][col] = 1;
            else if (s == '0')
                mat[row][col] = 0;
            else if (s == '2')
                mat[row][col] = 2;
            else if (s == '3')
                mat[row][col] = 3;
            else
                mat[row][col] = 0; // par défaut
        }
    }

    return mat;
}
