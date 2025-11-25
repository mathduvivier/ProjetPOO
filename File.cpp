#include "File.h"
#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include "Grid.h"
using namespace std;

File(){}

Grid File::FileRead(const string& FileName){
// Lit le contenu d'un fichier texte
    int i=0;
    int height;
    int width;
    int value;
    vector<vector<int>> GridMat;//vecteur de vecteur Gridmat
    ifstream fin(FileName);//lecture du fichier

    if (!fin.is_open()) {//Si le fichier n'est pas lu
        cerr << "Error : unable to open File " << FileName << endl;//sortie d'erreur
        exit(1);
    }

    string content, line;
    getline(fin, line);//prends la ligne de fin est la met dans line
    istringstream iss(line);//récupération des caractères de la premieère ligne
    iss>>height;//1er caractère = height
    iss>>width;//2e caractère = width
    int j=0;
    while (getline(fin, line)) {//permet de passer d'une ligne à une autre
	istringstream iss(line);//iss permet de prendre les caractères de la ligne
        i=0;
    	while (iss >> value) {//met les caractères pris pas iss est les met dans value
        	GridMat[j][i]=value;//pour chaque coordonnnées on donne la valeur récupéré par iss
		i++;
    	}
	j++;
    }

    fin.close();
    Grid g(height, width, GridMat);
    return g;
}
}
void WriteFile(Grid g){
// Écrit du texte dans un fichier
    int i=0;
    int j=0;
    int height = g.get_height();
    int width = g.get_width();
    int value;
    vector<vector<int>> GridMat = g.get_Mat();
    ofstream fout(FileName);
    if (!fout.is_open()) {
        cerr << "Error: enable to write in " << FileName << endl;
        exit(1);
    }

    fout << height << " " << width << endl;//sortie des paramèetres de notre matrice, height et width
    for (j=0, j<height, j++){//Pour j allant de 0 à height on incrémente j
    	for (i=0, i<width, i++){//Pour i allant de 0 à width on incrémente i
    		fout<<GridMat[j][i]<<" ";//sort la première ligne de la matrice avec un espace
    	}
    	fout<<endl;
    }
    fout.close();
}
}
