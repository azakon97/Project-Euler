#include "Problem8.h"
#include <iostream>
#include <fstream>

/** Problem 8
 * The four adjacent digits in the 1000-digit number that have the greatest product are 9 × 9 × 8 × 9 = 5832.
 * Find the thirteen adjacent digits in the 1000-digit number that have the greatest product. What is the value of this product?
 */

void readNumFromFile(int* number) {
    char current_char;
    std::ifstream in;
    in.open(R"(C:\Users\Sergey\Desktop\Sasha\Project-Euler\src\Problem8\number.txt)", std::ios::in);

    if (!in) {
        std::cerr << "Unable to open file datafile.txt";
        exit(1);   // call system to stop
    }

    int index = 0;

    while (!in.eof()) {
        in.get(current_char);
        if (current_char != '\n') {
            number[index] = current_char - '0';
            index++;
        }
    }

    in.close();
}

/**
 *
 * @param number - an array of digits representing a large number (1000 digits)
 * @param num_multipliers  - number of adjacent digits used for calculating the product
 * @return the greatest product of 'num_multipliers' adjacent digits in 'number'
 */
unsigned long long greatestAdjacentProduct(const int* number, int num_multipliers) {
    int start, end;
    start = 0;
    end = 0;
    unsigned long long product, largest_product;
    product = 1;
    largest_product = 0;

    while (end < 1000) {
        if (number[end] == 0) {
            end++;
            start = end;
            product = 1;
        } else if (end - start == num_multipliers-1) {
            product *= number[end];
            end++;
            if (product > largest_product)
                largest_product = product;
            product /= number[start];
            start++;

        } else {
            product *= number[end];
            end++;
        }
    }
    return largest_product;
}



void problem8() {
    int number[1001];
    readNumFromFile(number);
    std::cout << greatestAdjacentProduct(number, 13) << std::endl;
}