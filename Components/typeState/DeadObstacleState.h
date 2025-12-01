#ifndef DEADOBSTACLESTATE_H
#define DEADOBSTACLESTATE_H

#include "State.h"

// Représente une cellule qui est un obstacle mais qui est considérée comme "morte".
// Implémente les méthodes de l’interface State.
class DeadObstacleState : public State {
public:
    // Un obstacle mort n'est pas vivant.
    bool isAlive() const override { return false; }

    // Symbole utilisé pour représenter un obstacle mort.
    char getSymbol() const override { return '3'; }

    // Indique qu'il s'agit d'un obstacle.
    bool isObstacle() const override { return true; }
};

#endif
