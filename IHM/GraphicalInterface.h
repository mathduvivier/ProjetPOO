#ifndef GRAPHICALINTERFACE_H
#define GRAPHICALINTERFACE_H

#include "Grid.h"

// Cette classe est une interface abstraite destinée à représenter n’importe
// quelle interface graphique pour afficher le Jeu de la Vie.
// Elle définit les fonctions que toute implémentation graphique doit fournir.
class GraphicalInterface {
public:

    // Affiche la grille dans l’interface graphique
    virtual void displayGrid(const Grid& grid) = 0;

    // Indique si la fenêtre ou l’interface est encore ouverte
    virtual bool isOpen() const = 0;

    // Gère les événements utilisateur (clavier, souris, fermeture, etc.)
    virtual void pollEvents() = 0;

    // Destructeur virtuel pour libération correcte via un pointeur de base
    virtual ~GraphicalInterface() {}
};

#endif
