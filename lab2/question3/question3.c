#include <stdio.h>

int main(void) {
    int a = 0;
    int b = 0;
    int originalB;
    int count = 0;
    int isWholeNumberLog = 1;

    printf("Enter  your number for base a: ");
    scanf("%d", &a);

    printf("Enter your number for b: ");
    scanf("%d", &b);

    originalB = b;

    while (b > 1 && isWholeNumberLog == 1) {
        if (b % a == 0) {
            b = b / a;
            count++;
        } else {
            isWholeNumberLog = 0;
        }
    }

    if (isWholeNumberLog == 1) {
        printf("log base %d of %d is %d\n", a, originalB, count);
    } else {
        printf("log base %d of %d is not a whole-number logarithm\n", a, originalB);
    }

    return 0;
}