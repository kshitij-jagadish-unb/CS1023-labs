#include <stdio.h>

int array[] = {4, 9, 2, 12, 7}; 
int size = 5;

int recursiveMaximum(int array[], int size) {
    int remainingMax = 0;

    if (size == 1) {

        return array[0];
    }

    remainingMax = recursiveMaximum(array, size - 1);

    if (array[size - 1] > remainingMax) {

        return array[size - 1];
    }
    else {

        return remainingMax;
    }
}

int recursiveMinimum(int array[], int size) {
    int remainingMin = 0;

    if (size == 1){

        return array[0];
    }

    remainingMin = recursiveMinimum(array, size -1);

    if (array[size -1] < remainingMin) {

        return array[size-1];
    }
    else {

        return remainingMin;
    }
}

int main(void) {

    int Maximum = recursiveMaximum(array, size);
    int Minimum = recursiveMinimum(array, size);

    printf("The Maximum you want: %d\n", Maximum);
    printf("The Minimum you want: %d\n", Minimum);

    return 0;
}
