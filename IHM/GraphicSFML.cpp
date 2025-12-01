#include "GraphicSFML.h"

GraphicSFML::GraphicSFML(int cellSize, int width, int height)
    : cellSize(cellSize),
      window(sf::VideoMode(width * cellSize, height * cellSize), "Game of Life")
{}

void GraphicSFML::pollEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}
void GraphicSFML::displayGrid(const Grid& grid)
{
    window.clear();

    sf::RectangleShape cellShape(sf::Vector2f(cellSize - 1, cellSize - 1));

    for (int row = 0; row < grid.get_height(); row++) {
        for (int col = 0; col < grid.get_width(); col++) {

            bool CellAlive = grid.get_Cell(row, col)->isAlive();
            bool CellObstacle = grid.get_Cell(row, col)->isObstacle();

            if (CellAlive && !CellObstacle) {
                cellShape.setFillColor(sf::Color::Green);
            }
            else if (CellAlive && CellObstacle) {
                cellShape.setFillColor(sf::Color::Magenta);
            }
            else if (!CellAlive && CellObstacle) {
                cellShape.setFillColor(sf::Color::Red);
            }
            else {
                cellShape.setFillColor(sf::Color::Blue);
            }

            cellShape.setPosition(col * cellSize, row * cellSize);
            window.draw(cellShape);
        }
    }

    window.display();
}
