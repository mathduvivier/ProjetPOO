#ifndef ALIVEOBSTACLESTATE_H
#define ALIVEOBSTACLESTATE_H

#include "State.h"

class AliveObstacleState : public State {
public:
    bool isAlive() const override { return true; }
    char getSymbol() const override { return '2'; }
    bool isObstacle() const override { return true; }
};

#endif

