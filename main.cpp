#include <iostream>
#include "File.h"
#include "Grid.h"
#include "GameOfLife.h"
#include "GraphicSFML.h"

using namespace std;

// ===== MENU =====
void displayMenu() {
    cout << "=== Jeu de la Vie ===" << endl;
    cout << "1. Mode Graphique (SFML)" << endl;
    cout << "2. Mode Console (fichiers d’iterations)" << endl;
    cout << "3. Test unitaire (afficher un fichier iteration_X)" << endl;
    cout << "4. Quitter" << endl;
    cout << "Votre choix : ";
}

int main()
{
    string filename;
    cout << "Nom du fichier d'entrée : ";
    cin >> filename;

    File fichier;

    int choix = 0;

    do {
        displayMenu();
        cin >> choix;

        switch (choix) {

        // ======================= MODE GRAPHIQUE =======================
        case 1: {
            // Charger une NOUVELLE grille pour ce mode
            Grid g = fichier.FileRead(filename);

            GraphicSFML gui(50, g.get_width(), g.get_height());

            while (gui.isOpen()) {
                gui.pollEvents();
                gui.displayGrid(g);
                sf::sleep(sf::seconds(0.3));
                g.update();
            }
            break;
        }

        // ======================= MODE CONSOLE =========================
        case 2: {
            int steps;
            cout << "Combien d'iterations ? ";
            cin >> steps;

            // Charger une NOUVELLE grille pour ce mode
            Grid g = fichier.FileRead(filename);
            GameOfLife sim(g);

            sim.runConsole(steps, fichier);  // TON runConsole(File&) est respecté

            cout << "Fichiers créés." << endl;
            break;
        }

        // ======================= TEST UNITAIRE ========================
        case 3: {
            int num;
            cout << "Quel fichier iteration_X afficher ? ";
            cin >> num;

            fichier.displayIterationFile(num);
            break;
        }

        case 4:
            cout << "Au revoir !" << endl;
            break;

        default:
            cout << "Option invalide." << endl;
        }

    } while (choix != 4);

    return 0;
}
