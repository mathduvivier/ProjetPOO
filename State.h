#ifndef STATE_H
#define STATE_H

class State {
public:
    virtual bool isAlive() const = 0;
    virtual char getSymbol() const = 0;
    virtual bool isObstacle() const = 0;
    virtual ~State() {}
};

#endif
