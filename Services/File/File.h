#ifndef FILE_H
#define FILE_H

#include <string>
#include <vector>
#include "Grid.h"

// Cette classe gère toutes les opérations liées aux fichiers.
// Elle permet de lire une grille depuis un fichier, d’écrire les itérations
// et d’afficher un fichier d'itération particulier.
class File {

public:
    // Constructeur simple sans paramètres
    File() {}

    // Lit un fichier et retourne une grille initialisée selon son contenu
    Grid FileRead(const std::string& FileName);

    // Écrit l’état d’une grille dans un fichier donné
    void WriteFile(const std::string& FileName, const Grid& g) const;

    // Affiche un fichier iteration_X dans la console
    void displayIterationFile(int iteration) const;
};

#endif
