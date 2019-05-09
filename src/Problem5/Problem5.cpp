#include <iostream>
#include "Problem5.h"
#include "../Util/Util.h"

/** Problem 5
 * 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
 * What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
 */

/**
 * Function that find the smallest number that is divisible by every integer between min and max inclusive
 * @param min
 * @param max
 * @return smallest number that is divisible by every integer between min and max
 */
unsigned long long smallestMultiple(unsigned long long min, unsigned long long max) {
    unsigned long long result = min;
    for (unsigned long long i = min; i <= max; i++) {
        if (isPrime(i)) {
            result *= i;
        }
        else {
            result *= (lcm(i, result) / result);
        }
    }
    return result;
}


void problem5() {
    std::cout << smallestMultiple(1, 20) << std::endl ;
}