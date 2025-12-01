#ifndef ALIVESTATE_H
#define ALIVESTATE_H

#include "State.h"

// Représente l’état d’une cellule vivante.
// Implémente les méthodes définies dans la classe abstraite State.
class AliveState : public State {
public:
    // Une cellule vivante renvoie toujours vrai ici.
    bool isAlive() const override { return true; }

    // Symbole utilisé pour représenter une cellule vivante.
    char getSymbol() const override { return '1'; }

    // Une cellule vivante n’est pas un obstacle.
    bool isObstacle() const override { return false; }
};

#endif
