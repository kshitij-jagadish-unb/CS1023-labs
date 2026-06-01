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

int main(void) {     
    
    int base = 0;
    int exponent = 0;

    printf("Gimme your base number: ");     
    scanf("%d", &base);                      

    printf("Gimme your exponental increment: ");      
    scanf("%d", &exponent);

    printf("Your Answer is: ");     
    printf("%d\n", power(base, exponent));

    return 0;
}