#include <stdio.h>

int main(void) {

    int row = 1;
    int spaces;
    int stars;

    while (row <= 5) {

        spaces = 1;

        while (spaces <= 5 - row) {

            printf(" ");
            spaces = spaces + 1;
        }

        stars = 1;

        while (stars <= (2 * row - 1)) {

            printf("*");
            stars = stars + 1;
        }

        printf("\n");

        row = row + 1;
    }

    row = 4;

    while (row >= 1) {

        spaces = 1;

        while (spaces <= 5 - row) {

            printf(" ");
            spaces = spaces + 1;
        }

        stars = 1;

        while (stars <= (2 * row - 1)) {
            
            printf("*");
            stars = stars + 1;
        }

        printf("\n");

        row = row - 1;
    }

    return 0;
}