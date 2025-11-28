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

    for (int row = 0; row < height; row++)
        for (int col = 0; col < width; col++)
            fin >> matrix[row][col];

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

    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            fout << g.get_Cell(row,col)->getSymbol() << " ";
        }
        fout << endl;
    }

    fout.close();
}
void File::writeIteration(const std::vector<std::vector<int>>& mat, int iteration) const
{
    std::ostringstream name;
    name << "iteration_" << iteration << ".txt";

    std::ofstream fout(name.str());
    if (!fout.is_open()) {
        std::cerr << "Erreur : impossible d’écrire " << name.str() << std::endl;
        return;
    }

    int h = mat.size();
    int w = mat[0].size();

    fout << h << " " << w << "\n";

    for (int r = 0; r < h; r++) {
        for (int c = 0; c < w; c++) {
            fout << mat[r][c] << " ";
        }
        fout << "\n";
    }

    fout.close();
}
void File::displayIterationFile(int iteration) const
{
    std::ostringstream name;
    name << "iteration_" << iteration << ".txt";

    std::ifstream fin(name.str());
    if (!fin.is_open()) {
        std::cerr << "Erreur : fichier introuvable : " << name.str() << std::endl;
        return;
    }

    std::string line;

    while (std::getline(fin, line)) {
        std::cout << line << std::endl;
    }

    fin.close();
}
