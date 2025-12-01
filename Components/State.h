#ifndef STATE_H
#define STATE_H

// La classe State est une classe abstraite représentant l'état d'une cellule.
// Elle définit une interface que toutes les classes d'état doivent implémenter.
class State {
public:
    // Indique si l'état correspond à une cellule vivante.
    virtual bool isAlive() const = 0;

    // Retourne le symbole associé à cet état.
    virtual char getSymbol() const = 0;

    // Indique si l'état correspond à un obstacle.
    virtual bool isObstacle() const = 0;

    // Destructeur virtuel pour permettre une destruction correcte via un pointeur de base.
    virtual ~State() {}
};

#endif
