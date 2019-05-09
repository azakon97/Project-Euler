#include "Problem6.h"
#include <iostream>
#include <cmath>

/** Problem 6
 * The sum of the squares of the first ten natural numbers is,
 * 12 + 22 + ... + 102 = 385
 * The square of the sum of the first ten natural numbers is,
 * (1 + 2 + ... + 10)2 = 552 = 3025
 * Hence the difference between the sum of the squares of the first ten natural numbers and
 * the square of the sum is 3025 − 385 = 2640.
 * Find the difference between the sum of the squares of the first
 * one hundred natural numbers and the square of the sum.
 */

/**
 *
 * @param n
 * @return the sum of squares of all positive integers up to n
 */
int sumOfSquares(int n) {
    int sum;
    sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += (int) std::pow(i, 2);
    }
    return sum;
}

/**
 *
 * @param n
 * @return the square of the sum of the positive integers up to n
 */
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