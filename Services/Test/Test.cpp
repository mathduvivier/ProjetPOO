#include <cassert>
#include <iostream>
#include "Grid.h"
#include "GameOfLife.h"
#include "Test.h"

using namespace std;

void test_neighbors_basic() {
    vector<vector<int>> mat = {
        {1,0,0},
        {0,1,0},
        {0,0,0}
    };
    Grid g(3,3,mat);

    assert(g.calcCellNeighbors(0,0) == 1);
    assert(g.calcCellNeighbors(1,1) == 1);

    cout << "test_neighbors_basic OK" << endl;
}

void test_update_blinker() {
    vector<vector<int>> mat = {
        {0,1,0},
        {0,1,0},
        {0,1,0}
    };
    Grid g(3,3,mat);

    g.update();

    vector<vector<int>> expected = {
        {1,1,1},
        {1,1,1},
        {1,1,1}
    };

    auto result = g.getMatrix();

    for(int r=0;r<3;r++)
        for(int c=0;c<3;c++)
            assert(result[r][c] == expected[r][c]);

    cout << "test_update_blinker OK" << endl;
}

void runAllTests() {
    cout << "\n=== Lancement des tests unitaires ===\n" << endl;

    test_neighbors_basic();
    test_update_blinker();

    cout << "\nTous les tests ont réussi !" << endl;
}
