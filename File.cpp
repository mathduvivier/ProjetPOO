#include "File.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

Grid File::FileRead(const string& FileName)
{
    ifstream fin(FileName);

    if (!fin.is_open()) {
        cerr << "Error : unable to open File " << FileName << endl;
        exit(1);
    }

    int height, width;
    fin >> height >> width;

    vector<vector<int>> matrix(height, vector<int>(width));

    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            fin >> matrix[i][j];

    fin.close();
    return Grid(height, width, matrix);
}

void File::WriteFile(const string& FileName, const Grid& g)
{
    ofstream fout(FileName);

    if (!fout.is_open()) {
        cerr << "Error: unable to write to " << FileName << endl;
        exit(1);
    }

    int height = g.get_height();
    int width  = g.get_width();

    fout << height << " " << width << endl;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fout << g.get_Cell(i,j)->getSymbol() << " ";
        }
        fout << endl;
    }

    fout.close();
}
