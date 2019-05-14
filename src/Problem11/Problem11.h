#ifndef PROJECTEULER_PROBLEM11_H
#define PROJECTEULER_PROBLEM11_H

void problem11();

void readNumberGrid(int grid[20][20]);

int greatestAdjacentProduct(int num);

int rightDiagProduct(int grid[20][20], int i, int j);

int leftDiagProduct(int grid[20][20], int i, int j);

int vertProduct(int grid[20][20], int i, int j);

int horizProduct(int grid[20][20], int i, int j);
#endif //PROJECTEULER_PROBLEM11_H
