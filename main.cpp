#include "GameOfLife.h"
#include <vector>

int main()
{
    std::vector<std::vector<int>> mat = {
        {0,1,0,0,2},
        {0,1,0,0,0},
        {0,1,0,0,0},
        {0,0,0,1,0},
        {2,0,0,0,1}
    };

    GameOfLife game(5, 5, mat);
    game.run(5);

    return 0;
}
