#ifndef CELL_H
#define CELL_H

#include "State.h"

// La classe Cell représente une cellule qui possède un état.
// L'état est géré via un pointeur vers un objet de type State.
class Cell {
private:
    State* state; // Pointeur vers l'état actuel de la cellule

public:
    // Constructeur qui initialise la cellule avec un état donné
    Cell(State* s) : state(s) {}

    // Renvoie vrai si l'état de la cellule correspond à "vivant"
    bool isAlive() const { return state->isAlive(); }

    // Renvoie le symbole associé à l'état de la cellule
    char getSymbol() const { return state->getSymbol(); }

    // Renvoie vrai si la cellule est considérée comme un obstacle
    bool isObstacle() const { return state->isObstacle(); }

    // Modifie l'état de la cellule
    void setState(State* s) { state = s; }
};

#endif
