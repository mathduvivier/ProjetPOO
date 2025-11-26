#include <iostream>
#include "File.h"
#include "GameOfLife.h"

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
    cout << "Combien d'iterations voulez-vous ? ";
    cin >> iterations;

    game.run(iterations);

    return 0;
}

