#include <iostream>
#include <thread>
#include <chrono>

#include "File.h"
#include "Grid.h"
#include "GameOfLife.h"
#include "GraphicSFML.h"

using namespace std;

// ================== MENU ==================
void displayMenu() {
    cout << "=== Jeu de la Vie ===" << endl;
    cout << "1. Mode Graphique (SFML)" << endl;
    cout << "2. Mode Console (silencieux)" << endl;
    cout << "3. Test unitaire" << endl;
    cout << "4. Quitter" << endl;
    cout << "Choisissez une option : ";
}

// ================== TEST UNITAIRE ==================
void testUnitaire(Grid& grille) {
    int nb;
    cout << "Afficher quelle iteration ? ";
    cin >> nb;

    for (int i = 0; i < nb; i++) {
        grille.update();
    }

    grille.display(); // test = affichage console
}

// ================== PROGRAMME PRINCIPAL ==================
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

        // MODE GRAPHIQUE
        case 1: {
            // recharge grille initiale pour SFML
            Grid g2 = fichier.FileRead(filename);

            GraphicSFML gui(50, g2.get_width(), g2.get_height());

            while (gui.isOpen()) {
                gui.pollEvents();
                gui.displayGrid(g2);
                sf::sleep(sf::seconds(0.3));
                g2.update();
            }
            break;
        }

        // MODE CONSOLE (création fichiers)
        case 2: {
            int steps;
            cout << "Nombre d'iterations ? ";
            cin >> steps;

            Grid g3 = fichier.FileRead(filename); // recharge grille initiale

            GameOfLife sim(g3);
            sim.runConsole(steps, fichier);

            cout << "Fichiers créés pour chaque iteration." << endl;
            break;
        }

        // MODE TEST UNITAIRE
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
