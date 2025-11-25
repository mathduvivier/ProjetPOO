#ifndef ALIVESTATE_H
#define ALIVESTATE_H

#include "State.h"

class AliveState : public State {
public:
    bool isAlive() const override { return true; }
    char getSymbol() const override { return 'O'; }
};

#endif

