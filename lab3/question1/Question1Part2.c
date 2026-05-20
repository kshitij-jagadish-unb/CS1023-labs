#include <stdio.h>

int main(void) {
    int grade = 0;
    int Agrade = 0;
    int result = 0;

    printf("Enter Two grades: ");
    result = scanf("%d%d", &grade, &Agrade);

    printf("Number of inputs: %d\n", result);

    if (result == 2) {
        printf("The inputed grades are: %d, %d\n", grade, Agrade);
    }
    if (result == 1) {
        printf("You've only inputed 1 number. Try again: %d\n", grade);
    } 
    if (result == 0) {
        printf("Enter Numbers!");
    }

    return 0;
}