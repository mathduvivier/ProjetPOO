#ifndef CELL_H
#define CELL_H

#include "State.h"

class Cell {
private:
    State* state;

public:
    Cell(State* s) : state(s) {}

    bool isAlive() const { return state->isAlive(); }
    char getSymbol() const { return state->getSymbol(); }
    bool isObstacle() const { return state->isObstacle(); }

    void setState(State* s) { state = s; }
};

#endif
