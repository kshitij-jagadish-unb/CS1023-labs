#include <stdio.h>
#include <limits.h>


void printBits(unsigned int num) {

    int bits = sizeof(unsigned int) * CHAR_BIT;

    for (int i = bits - 1; i >= 0; i--) {

        if ((num >> i) & 1) {

            printf("1");
        }
        else {

            printf("0");
        }
    }

    printf("\n");
}

int main(void) {

    int num = 0;
    int shifted = 0;

    printf("Enter a number: ");
    scanf("%d", &num);

    printf("\n Your OG number: %d\n", num);
    printBits(num);

    shifted = num >> 4;

    printf("\n The Shifted Version: %d\n", shifted);
    printBits(shifted);

    return 0;
}

