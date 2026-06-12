#include <stdio.h>

union floatingPoint {

    float f;
    double d;
    long double x;
};

int main(void) {

    union floatingPoint no1;
    union floatingPoint no2;
    union floatingPoint no3;

    printf("Enter a decimal (float): ");
    scanf("%f", &no1.f);

    printf("Enter a longer decimal (double): ");
    scanf("%lf", &no2.d);

    printf("Enter a waaay longer decimal (long double): ");
    scanf("%lf", &no3.x);

    printf("\n");

    printf(" Your decimal (float): %f\n", no1.f);
    printf("Your longer decimal (Double): %lf\n", no2.d);
    printf("Your waaay longer decimal (Long Double): %lf\n", no3.x);

    printf("\n");

    printf("Size of float: %zu\n", sizeof(float));
    printf("Size of double: %zu\n", sizeof(double));
    printf("Size of long double: %zu\n", sizeof(long double));
    
    printf("Size of union: %zu\n", sizeof(union floatingPoint));

    return 0;
}