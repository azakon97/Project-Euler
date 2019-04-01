#include <iostream>
#include <vector>
#include "../../Util/src/Util.h"
#include "Problem3.h"
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
        std::cout << "hellos : " <<  n << std::endl;
        maxPrime = n;
    }

    return maxPrime;
}

void problem3() {
    std::cout << "answer " << largestPrimeFactor(NUMBER);
}
