// Si tu veux ignorer les obstacles#include "Grid.h"
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
int Grid::calcCellNeighbors(int x, int y){
	int count=0;
	static int dx[8] = {-1, -1, -1,  0, 0,  1, 1, 1};
	static int dy[8] = {-1,  0,  1, -1, 1, -1, 0, 1};

	for (int k = 0; k < 8; k++) {
        	int nx = (x + dx[k] + height) % height;//Grille thorique les cellules en hauts et en bas sont voisines
        	int ny = (y + dy[k] + width)  % width;//" les cellules à gauche et à droite sont voisines

	        if (GridCells[nx][ny]->isObstacle()) // ignore les obstacles
        	    continue;

        	if (GridCells[nx][ny]->isAlive())
          	  count++;
    	}

    	return count;
}


void Grid::update() {

    vector<vector<Cell*>> newGrid(height, vector<Cell*>(width)); // Nouvelle grille qui contiendra l'état mis à jour

    for (int x = 0; x < height; x++) { // Parcours de toutes les cellules de la grille
        for (int y = 0; y < width; y++) {

            Cell* transform = GridCells[x][y];// Cellule actuelle

            if (transform->isObstacle()) { // Si la cellule est un obstacle, elle reste telle quelle
                newGrid[x][y] = transform;
                continue; // on passe à la cellule suivante
            }
            int n = calcCellNeighbors(x, y);// Calcul du nombre de voisins vivants

            if (transform->isAlive()) {// Si la cellule est vivante
                if (n < 2 || n > 3)// Elle meurt si elle a moins de 2 ou plus de 3 voisins
                    newGrid[x][y] = new DeadCell();
                else// Sinon elle reste vivante
                    newGrid[x][y] = new AliveCell();
            }
            else { // Si la cellule est morte
                if (n == 3) // Elle naît si elle a exactement 3 voisins vivants
                    newGrid[x][y] = new AliveCell();
                else // Sinon elle reste morte
                    newGrid[x][y] = new DeadCell();
            }
        }
    }

    // Remplace l'ancienne grille par la nouvelle
    GridCells = newGrid;
}

void Grid::display() {
    for (int x = 0; x < height; x++) {// Parcours de toutes les lignes
        for (int y = 0; y < width; y++) {// Parcours de toutes les colonnes
            Cell* c = GridCells[x][y];// Récupération de la cellule à afficher
            if (c->isObstacle()) { // Si la cellule est un obstacle, on affiche #
                cout << "#";
            }
            else if (c->isAlive()) { // Sinon si elle est vivante, on affiche O
                cout << "O";
            }
            else { // Sinon elle est morte, on affiche .
                cout << ".";
            }
        }
        cout << endl;// Retour à la ligne pour afficher la rangée suivante
    }
}
