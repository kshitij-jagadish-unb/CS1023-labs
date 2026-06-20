#include <stdio.h>
#include <stdlib.h>

double *createScores(size_t count){

    double *new_memory =  (double *)malloc(count * sizeof(double));
    return new_memory;
}

void readScores(double scores[], size_t count){

    size_t x = 0;

    while (x < count){

        printf("Enter score(s) %zu :", x + 1);
        scanf("%lf", &scores[x]);

        x = x + 1;
    }
}

void printScores(const double scores[], size_t count){

    size_t x = 0;

    printf("Score(s) entered are: ");
    
    while (x < count){

        printf("%.2f", scores[x]);

        x = x + 1;
    }
    printf("\n");
    
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

