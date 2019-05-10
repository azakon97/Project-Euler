#include <vector>
#include "Util.h"
#include <iostream>
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
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

/**
 *
 * @param n
 * @return vector or all prime numbers smaller than n
 */
std::vector<unsigned long long> generatePrimes(unsigned long long n) {
    std::vector<unsigned long long> primes;
    primes.push_back(2);
    for (unsigned long long i = 3; i < n; i+=2) {
        if (isPrime(i)) {
            primes.push_back(i);
        }
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

