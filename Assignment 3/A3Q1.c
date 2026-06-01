#include <stdio.h>

int gcd(int x, int y) {   //Greatest Common Diviser Function
    if (y == 0) {

        printf("Undefined Buddy.");
        return x;    //Anything divided by 0 is undefined
    }
    else {

        return gcd(y, x % y);  //Divide
    }
}

int main(void) {     //Greatest Common Diviser Main Function
    
    int x = 0;
    int y = 0;

    printf("Gimme your first number: ");     //Asking for the 1st number
    scanf("%d", &x);                      

    printf("Gimme your second number: ");      //Asking for the 2nd number
    scanf("%d", &y);

    printf("Greatest Common Divisor of the numbers is: ");     //Returning the divided number
    printf("%d\n", gcd(x, y));

    return 0;
}