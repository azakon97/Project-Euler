#ifndef PROJECTEULER_UTIL_H
#define PROJECTEULER_UTIL_H
#include <vector>

int modulo(int a, int b);

bool isPrime(unsigned long long n);

std::vector<unsigned long long> generatePrimes(unsigned long long n);

unsigned long long generatePrime(unsigned long long n);

bool isPalindrome(int n, int *copy);

unsigned long long gcd(unsigned long long a, unsigned long long b);

unsigned long long lcm(unsigned long long a, unsigned long long b);

#endif //PROJECTEULER_UTIL_H
