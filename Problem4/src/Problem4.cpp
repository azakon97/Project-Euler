#include <iostream>
#include "Problem4.h"
#include "../../Util/src/Util.h"

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