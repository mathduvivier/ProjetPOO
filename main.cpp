#include <iostream>
#include "File.h"
#include "Grid.h"
#include "GameOfLife.h"
#include "GraphicSFML.h"

using namespace std;

// Affiche le menu principal du programme
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

    // On demande le nom du fichier contenant la grille initiale
    cout << "Nom du fichier d'entrée : ";
    cin >> filename;

    File fichier;

    int steps;
    // Nombre d’itérations du Game of Life à exécuter
    cout << "Combien d'iterations ? ";
    cin >> steps;

    int choix = 0;

    // Boucle principale du menu
    do {
        displayMenu();
        cin >> choix;

        switch (choix) {

        case 1: {
            // Mode graphique SFML
            // On charge la grille initiale depuis le fichier
            Grid g = fichier.FileRead(filename);
            GameOfLife sim(g);

            // Initialisation de la fenêtre graphique
            GraphicSFML gui(50, g.get_width(), g.get_height());

            // Exécution du Game of Life dans la fenêtre
            sim.runGraphical(steps, gui);

            break;
        }

        case 2: {
            // Mode console (sauvegarde des itérations dans des fichiers)
            Grid g = fichier.FileRead(filename);
            GameOfLife sim(g);

            // Génère les fichiers iteration_X
            sim.runConsole(steps, fichier);

            cout << "Fichiers créés." << endl;
            break;
        }

        case 3: {
            // Affichage d’un fichier d’itération déjà généré
            int num;
            cout << "Quel fichier iteration_X afficher ? ";
            cin >> num;

            fichier.displayIterationFile(num);
            break;
        }

        case 4:
            // Sortie du programme
            cout << "Au revoir !" << endl;
            break;

        default:
            // Mauvais choix dans le menu
            cout << "Option invalide." << endl;
        }

    } while (choix != 4); // On continue tant que l'utilisateur ne quitte pas

    return 0;
}
