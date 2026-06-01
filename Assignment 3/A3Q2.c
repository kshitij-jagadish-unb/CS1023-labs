#include <stdio.h>

int power(int base, int exponent) {   //power function

    // Base case
    if (exponent == 1) {

        return base;         //anything raised to 1 is the same thing
    }
    else {

        return base * power(base, exponent - 1);   //returns the exponential 
    }
}

int main(void) {     
    
    int base = 0;              //asking for the base and exponent
    int exponent = 0;

    printf("Gimme your base number: ");     
    scanf("%d", &base);                      

    printf("Gimme your exponental increment: ");      
    scanf("%d", &exponent);

    printf("Your Answer is: ");               //returns it 
    printf("%d\n", power(base, exponent));

    return 0;
}