#include <stdio.h>

int numbers[] = {2, 5, 8, 12, 16, 23, 38, 45, 56, 72};
int size = 10;
int key = 0;
int result = 0;

int binarySearch(int array[], int left, int right, int key) {

    int middle = 0;

    if (left > right) {

        return -1;
    }

    middle = (left + right) / 2;

    if (array[middle] == key) {

        return middle;
    }
    if (key < array[middle]) {

        return binarySearch(array, left, middle - 1, key);
    }
    else {

        return binarySearch(array, middle + 1, right, key);
    }
}

int main(void) {

    printf("Enter da search key: ");
    
    scanf("%d", &key);

    result = binarySearch(numbers, 0, size - 1, key);

    if (result == -1) {

        printf("%d was not found.\n", key);
    }
    else {

        printf("%d was found at index %d.\n", key, result);
    }

    return 0;
}