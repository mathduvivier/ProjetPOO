#ifndef FILE_H
#define FILE_H

#include <string>
#include <vector>
#include "Grid.h"

class File {

public:
    File() {}

    Grid FileRead(const std::string& FileName);
    void WriteFile(const std::string& FileName, const Grid& g) const;
    void displayIterationFile(int iteration) const;

};

#endif
