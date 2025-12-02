#ifndef GRID_H
#define GRID_H

#include <vector>
#include <iostream>

#include "Cell.h"
#include "typeState/AliveState.h"
#include "typeState/DeadState.h"
#include "typeState/AliveObstacleState.h"
#include "typeState/DeadObstacleState.h"

// La classe Grid représente une grille composée de cellules.
// Elle gère la création, la mise à jour et l'affichage de cette grille.
class Grid {

private:
    int height; // Hauteur de la grille
    int width;  // Largeur de la grille

    // Matrice de pointeurs vers des cellules
    std::vector<std::vector<Cell*>> GridCells;

public:
    // Constructeur qui initialise la grille en fonction d'une matrice d'entiers
    Grid(int height, int width, const std::vector<std::vector<int>>& GridMat);

    // Destructeur qui libère la mémoire des cellules
    ~Grid();

    // Constructeur de copie pour dupliquer correctement la grille
    Grid(const Grid& other);

    // Accesseurs pour hauteur et largeur
    int get_height() const { return height; }
    int get_width() const { return width; }

    // Retourne un pointeur vers une cellule à une position donnée
    Cell* get_Cell(int row, int col) const { return GridCells[row][col]; }

    // Calcule le nombre de voisins vivants d'une cellule donnée
    int calcCellNeighbors(int row, int col);

    // Met à jour la grille selon les règles du système
    void update();

    // Affiche la grille dans la console
    void display() const;

    bool testUpdate( Grid& oldGrid);

    // Renvoie une matrice d'entiers représentant les états des cellules
    std::vector<std::vector<int>> getMatrix() const;
};

#endif
