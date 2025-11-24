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
    vector<int> Gridvector;
    ifstream fin(FileName);

    if (!fin.is_open()) {
        cerr << "Error : unable to open File " << FileName << endl;
        exit(1);
    }

    string content, line;
    getline(fin, line);
    istringstream iss(line);
    iss>>height;
    iss>>width;
    while (getline(fin, line)) {
    	while (iss >> value) {
        	Gridvector[i]=value;
		i++;
    	}
    }

    fin.close();
    Grid g(height, width, Gridvector);
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
    vector<int> Gridvector = g.get_vector();
    ofstream fout(FileName);
    if (!fout.is_open()) {
        cerr << "Error: enable to write in " << FileName << endl;
        exit(1);
    }

    fout << height << " " << width << endl;
    for (j=0, j<height, j++){
    	for (i=0, i<width, i++){
    		fout<<vector[i+(j*width)]<<" ";
    	}
    	fout<<endl;
    }
    fout.close();
}
}
