#include "File.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

// Lit un fichier texte contenant les dimensions puis la matrice de la grille.
// Retourne un objet Grid initialisé avec ces données.
Grid File::FileRead(const string& FileName)
{
    ifstream fin(FileName);

    // Vérifie si le fichier peut être ouvert
    if (!fin.is_open()) {
        cerr << "Erreur : impossible d'ouvrir le fichier " << FileName << endl;
        exit(1);
    }

    int height, width;
    fin >> height >> width;

    // Vérifie que les dimensions sont valides
    if (!fin || height <= 0 || width <= 0) {
        cerr << "Erreur : dimensions invalides dans le fichier !" << endl;
        exit(1);
    }

    // Création de la matrice qui contiendra les valeurs lues
    vector<vector<int>> matrix(height, vector<int>(width));

    // Lecture des valeurs ligne par ligne
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {

            if (!(fin >> matrix[row][col])) {
                cerr << "Erreur : données manquantes à la ligne " << row
                     << ", colonne " << col << endl;
                exit(1);
            }
        }
    }

    // Vérifie qu’il n’y a pas de données en trop dans le fichier
    int extra;
    if (fin >> extra) {
        cerr << "Erreur : trop de données dans le fichier "
             << "(la grille dépasse les dimensions annoncées)" << endl;
        exit(1);
    }

    fin.close();

    // Création de la grille à partir des données lues
    return Grid(height, width, matrix);
}

// Écrit une grille dans un fichier en respectant le même format que la lecture
void File::WriteFile(const string& FileName, const Grid& g) const
{
    ofstream fout(FileName);

    // Vérifie l’ouverture du fichier
    if (!fout.is_open()) {
        cerr << "Error: unable to write to " << FileName << endl;
        exit(1);
    }

    int height = g.get_height();
    int width  = g.get_width();

    // Écrit les dimensions en première ligne
    fout << height << " " << width << endl;

    // Écrit chaque cellule en utilisant son symbole
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            fout << g.get_Cell(row,col)->getSymbol() << " ";
        }
        fout << endl;
    }

    fout.close();
}

// Affiche le contenu d’un fichier iteration_X.txt dans la console
void File::displayIterationFile(int iteration) const
{
    // Construction automatique du nom "iteration_X.txt"
    std::ostringstream name;
    name << "iteration_" << iteration << ".txt";

    std::ifstream fin(name.str());

    // Vérifie l’existence du fichier
    if (!fin.is_open()) {
        std::cerr << "Erreur : fichier introuvable : " << name.str() << std::endl;
        return;
    }

    // Lecture ligne par ligne et affichage
    std::string line;
    while (getline(fin, line)) {
        std::cout << line << std::endl;
    }

    fin.close();
}
