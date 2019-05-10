#include <iostream>
#include "Problem10.h"
#include "../Util/Util.h"

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