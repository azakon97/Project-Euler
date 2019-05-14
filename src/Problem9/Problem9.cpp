#include <iostream>
#include "Problem9.h"

/** Problem 9:
 * A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
 * a2 + b2 = c2
 * For example, 32 + 42 = 9 + 16 = 25 = 52.
 * There exists exactly one Pythagorean triplet for which a + b + c = 1000.
 * Find the product abc.
 */

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