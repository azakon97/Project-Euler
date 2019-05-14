#include <vector>
#include "Util.h"
#include <iostream>
#include <bitset>
/**
 * Function that calculates a modulo b even if a is negative
 * @param a
 * @param b
 * @return a modulo b
 */
int modulo(int a, int b) {
    const int result = a % b;
    return result >= 0 ? result : result + b;
}

/**
 *
 * @param n
 * @return true if n is prime and false otherwise
 */
bool isPrime(unsigned long long n) {
    if (n == 0 || n == 1)
        return false;
    double bound = sqrt(n);
    for (int i = 2; i <= bound; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

/**
 * Uses Sieve of Eratosthenes method to compute all primes until 20,000,000
 * @param *nums - the pointer to a bitset
 * @return vector or all prime numbers smaller than 20,000,000
 */
std::vector<unsigned> generatePrimes(std::bitset<20000000> *nums) {

    const unsigned until = nums->size();
    nums->set();
    nums->set(0, false);
    nums->set(1, false);

    double sieveBound = sqrt(until);


    for (unsigned i = 2; i < sieveBound; i++) {
        if ((*nums)[i]) {
            for (unsigned mult = i * 2; mult < until; mult += i) {
                nums->set(mult, false);
            }
        }
    }

    std::vector<unsigned> primes;
    for (unsigned int i = 0; i < until; i++) {
        if ((*nums)[i])
            primes.push_back(i);
    }
    return primes;
}

/**
 * Uses Sieve of Eratosthenes method to compute all primes until a specified integer
 * @param until - limit, all returned primes are smaller than 'until'
 * @return vector or all prime numbers smaller than 'until'
 */
std::vector<unsigned> generatePrimes(unsigned until) {

    std::vector<bool> nums(until, true);
    nums[0] = false;
    nums[1] = false;

    double sieveBound = sqrt(until);

    for (unsigned i = 2; i < sieveBound; i++) {
        if (nums[i]) {
            for (unsigned mult = i * 2; mult < until; mult += i) {
                nums[mult] = false;
            }
        }
    }

    std::vector<unsigned> primes;
    for (unsigned i = 0; i < until; i++) {
        if (nums[i])
            primes.push_back(i);
    }
    return primes;
}

/**
 *
 * @param n
 * @return nth prime number
 */
unsigned long long generatePrime(unsigned long long n) {
    if (n == 1)
        return 2;
    unsigned long long counter;
    counter = 1;
    unsigned long long primeCandidate;
    primeCandidate = 1;
    while (counter < n) {
        // increase by 2 because there are no even primes other than 2
        primeCandidate += 2;

        if (isPrime(primeCandidate))
            counter++;
    }
    return primeCandidate;
}

/**
 * Function that computes the number of divisors by performing prime factorisation
 * The total number of divisors of N can be expressed as D(N) = (a+1)(b+1)(c+1)...
 * where a, b, c ... are exponents of the prime factors of N
 * @param number - the number that we are finding the prime factorisation of
 * @param primes - vector of prime numbers used to find the factorisation
 * @return number of divisors of 'number'
 */
unsigned primeFactorisationNumDivisors(unsigned number, std::vector<unsigned> primes) {
    unsigned numDivisors = 1;
    unsigned exponent;
    unsigned remainder = number;
    for (unsigned i = 0; i < primes.size(); i++) {
        // If there is a remainder > 1 once we reached the square root of the number,
        // then it is a prime factor, the exponent of that factor is 1, so we multiply by 2
        if (primes[i] * primes[i] > number)
            return numDivisors * 2;

        exponent = 0;
        // For each prime we find the exponent and multiply number of divisors by (1 + exponent)
        while (remainder % primes[i] == 0) {
            exponent++;
            remainder = remainder / primes[i];
        }
        numDivisors *= (exponent + 1);

        // If there is no remainder, then we are done
        if (remainder == 1)
            return numDivisors;
    }
    return numDivisors;
}

/**
 * Function that recursively checks if a number is a palindrome
 * @param n - number that we perform the check on
 * @param copy - shared copy of n among all recursive calls
 * @return true if n is a palindrome, false otherwise
 */
bool isPalindrome(int n, int *copy) {
    // Base case: when n is a single digit we compare it to the last digit of *copy
    // essentially comparing first and last digit
    if (n >= 0 && n < 10) {
        return n == (*copy) % 10;
    }

    // Recursive call: the copy of n is shared among all recursive calls
    if (!isPalindrome(n/10, copy)) {
        return false;
    }

    // Divide the copy by 10 as we move up the recursion tree
    *copy /= 10;

    // Compare the i'th digit from beginning with i'th digit from the end
    return n % 10 == (*copy) % 10;
}

/**
 * Finds the greatest common divisor (gcd) of two integers
 * @param a - first integer
 * @param b - second integer
 * @return greatest common divisor (gcd) of a and b
 */
unsigned long long gcd(unsigned long long a, unsigned long long b) {
    unsigned long long c;
    while (a != 0) {
        c = a;
        a = b % a;
        b = c;
    }
    return b;
}

/**
 * Finds the lowest common multiple (lcm) of two integers
 * @param a - first integer
 * @param b - second integer
 * @return lowest common multiple of a and b
 */
unsigned long long lcm(unsigned long long a, unsigned long long b) {
    return a * (b / gcd(a, b));
}

int max2(int a, int b) {
    return a < b ? b : a;
}

int max3(int a, int b, int c) {
    return max2(a, b) < c ? c : max2(a, b);
}