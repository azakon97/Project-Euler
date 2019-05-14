#include <iostream>
#include "Problem10.h"
#include "../Util/Util.h"

/** Problem 10:
 * The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
 * Find the sum of all the primes below two million.
 */

/**
 * @param max
 * @return the sum of all primes below 'max'
 */

unsigned long long sumPrimes(unsigned long long max) {
    unsigned long long sum = 2;
    for (unsigned long long i = 3; i < max; i+=2) {
        if (isPrime(i)) {
            sum += i;
        }
    }
    return sum;
}

void problem10() {
    std::cout << sumPrimes(2000000) << std::endl;
}