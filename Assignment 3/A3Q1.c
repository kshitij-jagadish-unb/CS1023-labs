#include <stdio.h>

int gcd(int x, int y) {
    if (y == 0) {

        return x;
    }
    else {

        return gcd(y, x % y);
    }
}

int main(void) {
    
    int x = 0;
    int y = 0;

    printf("Gimme your first number: ");
    scanf("%d", &x);

    printf("Gimme your second number: ");
    scanf("%d", &y);

    printf("Greatest Common Divisor of the numbers is: ");
    printf("%d\n", gcd(x, y));

    return 0;
}