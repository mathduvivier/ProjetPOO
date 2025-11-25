#ifndef DEADSTATE_H
#define DEADSTATE_H

#include "State.h"

class DeadState : public State {
public:
    bool isAlive() const override { return false; }
    char getSymbol() const override { return '.'; }
};

#endif
