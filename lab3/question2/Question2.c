#include <stdio.h>

void toQualityPoints(){

    int average = 0;
    printf("Enter the Average: ");
    scanf("%d", &average);

    if(average >= 90 && average <= 100 ){
        printf("Quality Points -> 4");
    }
    if(average >= 80 && average <= 89){
        printf("Quality Points -> 3");
    }
    if(average >= 70 && average <= 79){
        printf("Quality Points -> 2");
    }
    if(average >= 60 && average <= 69){
        printf("Quality Points -> 1");
    }
    if(average < 60){
        printf("Quality Points -> 0");
    }
}

int main(void) {

    toQualityPoints();

    return 0;
}