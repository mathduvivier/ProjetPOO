#ifndef FILE_H
#define FILE_H
#include "Grid.h"
#include <string>

using namespace std;
class File{
private:
	string FileName;
public:
	File();
	Grid FileRead(string FileName);
	void WriteFile(Grid);
};
#endif
