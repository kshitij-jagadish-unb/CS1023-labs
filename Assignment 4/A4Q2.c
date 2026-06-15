#include <stdio.h>

#define ROWS 3
#define COLS 4

void printArray(int arr[ROWS][COLS])
{
    int row, col;

    for (row = 0; row < ROWS; row++)
    {
        for (col = 0; col < COLS; col++)
        {
            printf("%4d", arr[row][col]);
        }
        printf("\n");
    }
}

void sortArray(int arr[ROWS][COLS])
{
    int total = ROWS * COLS;

    int i, j;
    int minIndex;
    int currentRow, currentCol;
    int minRow, minCol;
    int searchRow, searchCol;
    int temp;

    for (i = 0; i < total - 1; i++)
    {
        minIndex = i;

        for (j = i + 1; j < total; j++)
        {
            searchRow = j / COLS;
            searchCol = j % COLS;

            minRow = minIndex / COLS;
            minCol = minIndex % COLS;

            if (arr[searchRow][searchCol] <
                arr[minRow][minCol])
            {
                minIndex = j;
            }
        }

        currentRow = i / COLS;
        currentCol = i % COLS;

        minRow = minIndex / COLS;
        minCol = minIndex % COLS;

        temp = arr[currentRow][currentCol];
        arr[currentRow][currentCol] =
            arr[minRow][minCol];
        arr[minRow][minCol] = temp;
    }
}

int main()
{
    int numbers[ROWS][COLS] =
    {
        {7, 3, 9, 1},
        {8, 2, 5, 4},
        {12, 6, 11, 10}
    };

    printf("Original array:\n");
    printArray(numbers);

    sortArray(numbers);

    printf("\nSorted array:\n");
    printArray(numbers);

    return 0;
}

