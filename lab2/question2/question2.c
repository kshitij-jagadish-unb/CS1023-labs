#include <stdio.h>

int main(void) {

    printf("Enter any 5 digit number: ");

    int numfive = 0;

    scanf("%d", &numfive);

    int counter = 1;
    int divider = 10000;

    while (counter <= 5) {
        
        int digit = numfive/divider;

        printf("%d\n", digit);

        numfive = numfive % divider;

        divider = divider/10;

        counter += 1;
    }

    return 0;
}