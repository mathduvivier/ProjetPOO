#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "State.h"

class Obstacle : public State {
public:
    bool isAlive() const override { return false; }   // un obstacle ne compte jamais comme vivant
    char getSymbol() const override { return '2'; }    // symbole d'affichage
};

#endif
