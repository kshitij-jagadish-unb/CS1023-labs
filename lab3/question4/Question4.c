#include <stdio.h>
#include <math.h>

double distance(double x1, double y1, double x2, double y2){

    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

}

int main(void){

    double x1 = 0;
    double x2 = 0;
    double y1 = 0;
    double y2 = 0;

    double ans = 0;

    printf("Gimme x1: ");

    scanf ("%lf", &x1);

    printf("Gimme x2: ");

    scanf ("%lf", &x2);

    printf("Gimme y1: ");

    scanf ("%lf", &y1);

    printf("Gimmer y2: ");

    scanf ("%lf", &y2);

    ans = distance(x1, x2, y1, y2);

    printf("The Distance is: %.1f \n", ans);

    return 0;
}