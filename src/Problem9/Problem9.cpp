#include <iostream>
#include "Problem9.h"

/**
 * Brute force algorithm for finding the product of Pythagorian triplet
 * @param sum - the sum of the Pythagorian triplet
 * @return the product of the Pythagorian triplet
 */
int productPythagoreanTriplet(int sum) {
    int a,b,c;
    for (a = 2; a < sum/2; a++) {
        for (b = a; b < sum/2; b++) {
            c = sum - a - b;
            if (a*a + b*b == c*c) {
                return a*b*c;
            }
        }
    }
    return -1;
}

void problem9() {
    std::cout << productPythagoreanTriplet(1000) << std::endl;
}