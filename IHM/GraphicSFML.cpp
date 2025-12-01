#include "GraphicSFML.h"

// Constructeur : initialise la taille d’une cellule et crée la fenêtre SFML
// La fenêtre fait width * cellSize pixels de large et height * cellSize pixels de haut.
GraphicSFML::GraphicSFML(int cellSize, int width, int height)
    : cellSize(cellSize),
      window(sf::VideoMode(width * cellSize, height * cellSize), "Game of Life")
{}

// Gère les événements SFML (par exemple fermeture de la fenêtre)
void GraphicSFML::pollEvents() {
    sf::Event event;

    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}

// Affiche la grille dans la fenêtre graphique
void GraphicSFML::displayGrid(const Grid& grid)
{
    // Efface l’écran avant de redessiner
    window.clear();

    // Forme utilisée pour dessiner chaque cellule (un carré)
    sf::RectangleShape cellShape(sf::Vector2f(cellSize - 1, cellSize - 1));

    // Parcours de toutes les cellules de la grille
    for (int row = 0; row < grid.get_height(); row++) {
        for (int col = 0; col < grid.get_width(); col++) {

            // Récupère les propriétés de la cellule
            bool CellAlive = grid.get_Cell(row, col)->isAlive();
            bool CellObstacle = grid.get_Cell(row, col)->isObstacle();

            // Choix de la couleur selon le type de cellule
            if (CellAlive && !CellObstacle) {
                cellShape.setFillColor(sf::Color::Green);      // cellule vivante
            }
            else if (CellAlive && CellObstacle) {
                cellShape.setFillColor(sf::Color::Magenta);    // obstacle vivant
            }
            else if (!CellAlive && CellObstacle) {
                cellShape.setFillColor(sf::Color::Red);        // obstacle mort
            }
            else {
                cellShape.setFillColor(sf::Color::Blue);       // cellule morte
            }

            // Position du carré dans la fenêtre
            cellShape.setPosition(col * cellSize, row * cellSize);

            // Dessin de la cellule
            window.draw(cellShape);
        }
    }

    // Affiche le rendu final
    window.display();
}
