#include "Problem6.h"
#include <iostream>
#include <cmath>

int sumOfSquares(int n) {
    int sum;
    sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += (int) std::pow(i, 2);
    }
    return sum;
}

int squareOfSum(int n) {
    int sum;
    // Using Gaussian method to calculate the sum of consecutive integers
    if (n % 2 == 0)
        sum = (1 + n) * (n/2);
    else
        sum = n + n * (n-1)/2;
    return  (int) std::pow(sum, 2);
}


void problem6() {
    std::cout << squareOfSum(100) - sumOfSquares(100) << std::endl ;
}