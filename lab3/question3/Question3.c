#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int flip(){

    return rand() % 2;
}

int main(void) {

    srand(time(NULL));

    int heads = 0;
    int tails = 0;
    int result = 0;
    int i = 1;

    while(i <= 100){
        result = flip();

        if(result == 1){
            printf("Heads \n");
            heads = heads + 1;
        }
        else{
            printf("Tails \n");
            tails = tails + 1;
        }

        i = i + 1;
    }

    printf("\nHeads: %d\n", heads);
    printf("Tails: %d\n", tails);

    return 0;
}