#include <stdio.h>

void printArray(int nums[], int size) {

    int i = 0;

    while (i < size) {

        printf("%d ", nums[i]);

        i = i + 1;
    }

    printf("\n");
}

void sortColors(int nums[], int size) {

    int zeros = 0;
    int ones = 0;
    int twos = 0;
    int i = 0;

    while (i < size) {

        if (nums[i] == 0) {

            zeros = zeros + 1;
        }
        if (nums[i] == 1) {

            ones = ones + 1;
        }
        else {

            twos = twos + 1;
        }

        i = i + 1;
    }

    i = 0;

    while (zeros > 0) {

        nums[i] = 0;

        i = i + 1;
        zeros = zeros - 1;
    }

    while (ones > 0) {

        nums[i] = 1;

        i = i + 1;
        ones = ones - 1;
    }

    while (twos > 0) {

        nums[i] = 2;

        i = i + 1;
        twos = twos - 1;
    }
}

int main(void) {

    int nums[] = {2, 0, 2, 1, 1, 0};
    int size = 6;

    printf("Before sorting: ");
    printArray(nums, size);

    sortColors(nums, size);

    printf("After sorting: ");
    printArray(nums, size);

    return 0;
}