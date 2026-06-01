#include <stdio.h>

int power(int base, int exponent) {

    // Base case
    if (exponent == 1) {

        return base;
    }
    else {

        return base * power(base, exponent - 1);
    }
}