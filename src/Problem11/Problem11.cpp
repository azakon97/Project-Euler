#include <fstream>
#include <iostream>
#include "Problem11.h"


void readNumberGrid(int grid[20][20]) {
    std::ifstream in;
    in.open(R"(C:\Users\Sergey\Desktop\Sasha\Project-Euler\src\Problem11\grid.txt)", std::ios::in);
    if (!in) {
        std::cerr << "Unable to open file datafile.txt";
        exit(1);   // call system to stop
    }


//    int n, i, j;
//    i = 0;
//    j = 0;
//
//    while (in >> n) {
//
//    }
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            in >> grid[i][j];
        }
    }

    in.close();
}

void problem11() {
    int grid[20][20];
    readNumberGrid(grid);
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            std::cout << grid[i][j] << " ";
        }
        std::cout << std::endl;
    }
}