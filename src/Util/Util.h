#ifndef PROJECTEULER_UTIL_H
#define PROJECTEULER_UTIL_H
#include <vector>
#include <bitset>

int modulo(int a, int b);

bool isPrime(unsigned long long n);

std::vector<unsigned> generatePrimes(std::bitset<20000000> *nums);

std::vector<unsigned> generatePrimes(unsigned until);

unsigned long long generatePrime(unsigned long long n);

unsigned int primeFactorisationNumDivisors(unsigned number, std::vector<unsigned> primes);

bool isPalindrome(int n, int *copy);

unsigned long long gcd(unsigned long long a, unsigned long long b);

unsigned long long lcm(unsigned long long a, unsigned long long b);

int max3(int a, int b, int c);

int max2(int a, int b);
#endif //PROJECTEULER_UTIL_H
