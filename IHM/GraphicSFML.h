#ifndef GRAPHICSFML_H
#define GRAPHICSFML_H

#include <SFML/Graphics.hpp>
#include "GraphicalInterface.h"
#include "Grid.h"

class GraphicSFML : public GraphicalInterface {

private:
    int cellSize;
    sf::RenderWindow window;

public:
    GraphicSFML(int cellSize, int width, int height);

    void displayGrid(const Grid& grid) override;
    bool isOpen() const override { return window.isOpen(); }
    void pollEvents() override;
};

#endif
