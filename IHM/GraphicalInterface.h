#ifndef GRAPHICALINTERFACE_H
#define GRAPHICALINTERFACE_H

#include "Grid.h"

class GraphicalInterface {
public:
    virtual void displayGrid(const Grid& grid) = 0;
    virtual bool isOpen() const = 0;
    virtual void pollEvents() = 0;
    virtual ~GraphicalInterface() {}
};

#endif
