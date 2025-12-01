#ifndef DEADSTATE_H
#define DEADSTATE_H

#include "State.h"

// Représente l’état d’une cellule morte.
// Implémente les méthodes définies dans la classe abstraite State.
class DeadState : public State {
public:
    // Une cellule morte renvoie toujours faux ici.
    bool isAlive() const override { return false; }

    // Symbole utilisé pour représenter une cellule morte.
    char getSymbol() const override { return '0'; }

    // Une cellule morte n’est pas un obstacle.
    bool isObstacle() const override { return false; }
};

#endif
