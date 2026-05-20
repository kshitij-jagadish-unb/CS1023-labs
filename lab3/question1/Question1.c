#include <stdio.h>

int main(void) {

    int grade = 0;
    int result = 0;

    printf("Enter a grade: ");
    result = scanf("%d", &grade);

    printf("Number of inputs: %d\n", result);

    if (result = 1){
        printf("The grade you've inputed is: %d", grade);
    }
    else{
        printf("Enter a Number!");
    }

    return 0;
}