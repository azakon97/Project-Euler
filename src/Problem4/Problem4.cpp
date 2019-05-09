#include <iostream>
#include "Problem4.h"
#include "../Util/Util.h"

/** Problem 4
 * A palindromic number reads the same both ways.
 * The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
 * Find the largest palindrome made from the product of two 3-digit numbers.
 */

/**
 *
 * @return largest palindrome that is a product of two 3-digit numbers
 */
int largestPalProduct() {
    int a, b, maxPalindrome, product, productCopy, *copy;
    maxPalindrome = 0;
    for (a = 100; a < 1000; a++) {
        // avoid duplicates
        for (b = 100; b <= a; b++) {
            product = a*b;
            productCopy = product;
            copy = &productCopy;
            if (product > maxPalindrome && isPalindrome(product, copy))
                maxPalindrome = product;
        }
    }
    return maxPalindrome;
}
void problem4() {
    std::cout << largestPalProduct() << std::endl ;
}