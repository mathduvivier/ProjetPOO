#ifndef DEADOBSTACLESTATE_H
#define DEADOBSTACLESTATE_H

#include "State.h"

class DeadObstacleState : public State {
public:
    bool isAlive() const override { return false; }
    char getSymbol() const override { return '3'; }
    bool isObstacle() const override {return true; }
};

#endif
