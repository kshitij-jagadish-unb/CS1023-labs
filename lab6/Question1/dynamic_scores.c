#include <stdio.h>
#include <stdlib.h>

double *createScores(size_t count){

    double *new_memory =  (double *)malloc(count * sizeof(double));
    return new_memory;
}










int main(void){

int inputsize = 0;
int incheck = 0;

printf("How many scores you wanna enter?");
scanf("%d", &inputsize);
incheck = inputsize;

if(incheck < 1){

    printf("Enter a positive number of scores >:| ");

    return 1;
}

    return 0;
}

