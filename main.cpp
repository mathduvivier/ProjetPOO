#include <iostream>
#include "File.h"
#include "GameOfLife.h"
#include "GraphicSFML.h"

using namespace std;

int main()
{
    string filename;

    cout << "Nom du fichier d'entree : ";
    cin >> filename;

    File f;
    Grid g = f.FileRead(filename);

    GameOfLife game(g);

    int iterations;
    cout << "Combien d'iterations ? ";
    cin >> iterations;

    // 1️⃣ Exécute le mode console
    game.runConsole(iterations);

    cout << "\nVoulez-vous voir le résultat en mode graphique ? (o/n) : ";
    char rep;
    cin >> rep;

    // 2️⃣ Lance mode graphique AVEC le résultat final
    if (rep == 'o' || rep == 'O') {

        // récupère la grille finale
        const Grid& finalGrid = game.getGrid();

        // crée SFML avec la grille finale
        GraphicSFML gui(20, finalGrid.get_width(), finalGrid.get_height());

        // crée un second GameOfLife basé sur la grille finale
        GameOfLife visual(finalGrid);

        // affiche l’évolution du résultat final
        visual.runGraphical(gui);
    }

    return 0;
}
