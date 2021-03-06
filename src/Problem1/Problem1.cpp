#include <iostream>
// Problem 1:
// If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9.
// The sum of these multiples is 23.
// Find the sum of all the multiples of 3 or 5 below 1000.
/**
 *
 * @param x
 * @return returns the sum of all the multiples of 3 or 5 below x
 */
int sumMultiples(int x) {
    int sum = 0;
    for (int i = 1; i < x; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            sum += i;
        }
    }
    return sum;
}

void problem1() {
    std::cout << sumMultiples(1000) << std::endl;
}