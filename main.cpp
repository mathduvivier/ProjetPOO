#include <iostream>
#include <limits>
#include "Test.h"
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
    cout << "3. Affichage (afficher un fichier iteration_X)" << endl;
    cout << "4. Test unitaires" << endl;
    cout << "5. Quitter" << endl;
    cout << "Votre choix : ";
}

int askPositiveInt(const string& message)
{
    int value;

    while (true) {
        cout << message;
        cin >> value;

        // Vérification : cin en erreur ou valeur négative / zéro
        if (cin.fail() || value <= 0) {

            cout << " Erreur : vous devez entrer un entier positif.\n\n";

            // Nettoyage du flux d'entrée
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        return value;
    }
}


int main()
{
    string filename;
    cout << "Nom du fichier d'entrée : ";
    cin >> filename;

    File fichier;

    //int steps;
    //cout << "Combien d'iterations ? ";
    //cin >> steps;

    int steps = askPositiveInt("Combien d'iterations ? ");

    int choix = 0;
    bool consoleUtilisee = false;   // <-- important

    do {
        displayMenu();
        cin >> choix;

        switch (choix) {

        // ======================= MODE GRAPHIQUE =======================
        case 1: {
            Grid g = fichier.FileRead(filename);
            GameOfLife sim(g);

            GraphicSFML gui(50, g.get_width(), g.get_height());

            sim.runGraphical(steps, gui);

            break;   // NE DÉBLOQUE PAS LE TEST UNITAIRE
        }

        // ======================= MODE CONSOLE =========================
        case 2: {
            Grid g = fichier.FileRead(filename);
            GameOfLife sim(g);

            sim.runConsole(steps, fichier);

            cout << "Fichiers créés." << endl;

            consoleUtilisee = true;   // <-- débloque le test unitaire
            break;
        }

        // ======================= TEST UNITAIRE ========================
        case 3: {

            if (!consoleUtilisee) {
                cout << " Erreur : Vous devez d'abord utiliser le mode console (option 2)"
                        " pour générer les fichiers iteration_X avant de lancer le test.\n";
                break;
            }

            int num;
            cout << "Quel fichier iteration_X afficher ? ";
            cin >> num;

            fichier.displayIterationFile(num);
            break;
        }
	case 4:
	    runAllTests();
	    break;

        case 5:
            cout << "Au revoir !" << endl;
            break;

        default:
            cout << "Option invalide." << endl;
        }

    } while (choix != 5);

    return 0;
}
