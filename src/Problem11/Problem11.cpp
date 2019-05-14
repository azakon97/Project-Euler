#include <fstream>
#include <iostream>
#include "Problem11.h"
#include "../Util/Util.h"

/** Problem 11:
 * In the 20×20 grid below, four numbers along a diagonal line have been marked in red.
 * The product of these numbers is 26 × 63 × 78 × 14 = 1788696.
 * What is the greatest product of four adjacent numbers in the same direction
 * (up, down, left, right, or diagonally) in the 20×20 grid?
 */

/**
 * Reads the the number grid from a file
 * @param grid
 */
void readNumberGrid(int grid[20][20]) {
    std::ifstream in;
    in.open(R"(C:\Users\Sergey\Desktop\Sasha\Project-Euler\src\Problem11\grid.txt)", std::ios::in);
    if (!in) {
        std::cerr << "Unable to open file datafile.txt";
        exit(1);   // call system to stop
    }

    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            in >> grid[i][j];
        }
    }

    in.close();
}

/**
 * @param grid
 * @return greatest adjacent product of 4 numbers in a 20 by 20 grid
 */
int greatestAdjacentProduct(int grid[20][20]) {
    int largestProduct = 0;
    int product;
    for (int i = 0; i < 17; i++) {
        for (int j = 0; j < 17; j++) {
            product = max3(rightDiagProduct(grid, i, j), vertProduct(grid, i, j), horizProduct(grid, i, j));
            if (product > largestProduct)
                largestProduct = product;
        }
    }
    for (int i = 17; i < 20; i++) {
        for (int j = 0; j < 17; j++) {
            product = horizProduct(grid, i, j);
            if (product > largestProduct)
                largestProduct = product;
        }
    }
    for (int j = 17; j < 20; j++) {
        for (int i = 0; i < 17; i++) {
            product = vertProduct(grid, i, j);
            if (product > largestProduct)
                largestProduct = product;
        }
    }

    for (int i = 0; i < 17; i++) {
        for (int j = 3; j < 20; j++) {
            product = leftDiagProduct(grid, i, j);
            if (product > largestProduct)
                largestProduct = product;
        }
    }
    return largestProduct;
}

/**
 * Returns the product of 4 adjacent numbers in a grid, going diagonally down
 * and right starting at point (i, j)
 */
int rightDiagProduct(int grid[20][20], int i, int j) {
    return grid[i][j] * grid[i+1][j+1] + grid[i+2][j+2] + grid[i+3][j+3];
}

/**
 * Returns the product of 4 adjacent numbers in a grid, going diagonally down
 * and left starting at point (i, j)
 */
int leftDiagProduct(int grid[20][20], int i, int j) {
    return grid[i][j] * grid[i+1][j-1] * grid[i+2][j-2] * grid[i+3][j-3];
}

/**
 * Returns the product of 4 adjacent numbers in a grid, going
 * vertically down starting at point (i, j)
 */
int vertProduct(int grid[20][20], int i, int j) {
    return grid[i][j] * grid[i+1][j] * grid[i+2][j] * grid[i+3][j];
}

/**
 * Returns the product of 4 adjacent numbers in a grid, going
 * horizontally across (left) starting at point (i, j)
 */
int horizProduct(int grid[20][20], int i, int j) {
    return grid[i][j] * grid[i][j+1] * grid[i][j+2] * grid[i][j+3];
}

void problem11() {
    int grid[20][20];
    readNumberGrid(grid);
    std::cout << greatestAdjacentProduct(grid);
}