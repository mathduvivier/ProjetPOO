#ifndef ALIVEOBSTACLESTATE_H
#define ALIVEOBSTACLESTATE_H

#include "State.h"

// Représente une cellule qui est un obstacle mais qui est considérée comme "vivante".
// Implémente les méthodes de l’interface State.
class AliveObstacleState : public State {
public:
    // Cet état est vivant.
    bool isAlive() const override { return true; }

    // Symbole utilisé pour représenter un obstacle vivant.
    char getSymbol() const override { return '2'; }

    // Indique qu'il s'agit bien d'un obstacle.
    bool isObstacle() const override { return true; }
};

#endif

