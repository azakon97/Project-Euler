#include <iostream>
#include <vector>
#include "../Util/Util.h"
#include "Problem3.h"

/** Problem 3:
 * The prime factors of 13195 are 5, 7, 13 and 29.
 * What is the largest prime factor of the number 600851475143 ?
 */


const long long NUMBER = 600851475143;

/**
 *
 * @param n
 * @return largest prime factor of n
 */
long long int largestPrimeFactor(long long int n) {
    long long int maxPrime = -1;

    while (n % 2 == 0) {
        maxPrime = 2;
        n /= 2;
    }

    // n must be odd at this point, hence iterate for odd integers
    for (int i = 3; i <= sqrt(n); i+= 2) {
        while (n % i == 0) {
            maxPrime = i;
            n /= i;
        }
    }

    // n is either
    if (n > 2) {
        maxPrime = n;
    }

    return maxPrime;
}

void problem3() {
    std::cout << largestPrimeFactor(NUMBER) << std::endl;
}
