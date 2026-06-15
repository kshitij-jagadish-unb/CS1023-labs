#include <stdio.h>

#define ROWS 12
#define COLS 12

void printMaze(char maze[ROWS][COLS])
{
    int row, col;

    for (row = 0; row < ROWS; row++)
    {
        for (col = 0; col < COLS; col++)
        {
            printf("%c ", maze[row][col]);
        }
        printf("\n");
    }
}

int traverseMaze(char maze[ROWS][COLS], int row, int col)
{
    /* Out of bounds */
    if (row < 0 || row >= ROWS ||
        col < 0 || col >= COLS)
    {
        return 0;
    }

    /* Wall */
    if (maze[row][col] == '#')
    {
        return 0;
    }

    /* Already visited */
    if (maze[row][col] == 'X' ||
        maze[row][col] == '*')
    {
        return 0;
    }

    /* Exit found */
    if (col == COLS - 1 && maze[row][col] == '.')
    {
        maze[row][col] = 'X';
        printMaze(maze);
        printf("\n");
        return 1;
    }

    /* Mark current position */
    maze[row][col] = 'X';

    printMaze(maze);
    printf("\n");

    /* Try moving Up */
    if (traverseMaze(maze, row - 1, col))
    {
        return 1;
    }

    /* Try moving Right */
    if (traverseMaze(maze, row, col + 1))
    {
        return 1;
    }

    /* Try moving Down */
    if (traverseMaze(maze, row + 1, col))
    {
        return 1;
    }

    /* Try moving Left */
    if (traverseMaze(maze, row, col - 1))
    {
        return 1;
    }

    /* Backtrack */
    maze[row][col] = '*';

    printMaze(maze);
    printf("\n");

    return 0;
}

int main()
{
    char maze[ROWS][COLS] =
    {
        {'#','#','#','#','#','#','#','#','#','#','#','#'},
        {'#','.','.','.','#','.','.','.','.','.','.','#'},
        {'.','.','#','.','#','.','#','#','#','#','.','#'},
        {'#','#','#','.','#','.','.','.','.','#','.','#'},
        {'#','.','.','.','.','#','#','#','.','#','.','.'},
        {'#','#','#','#','.','#','.','#','.','#','.','#'},
        {'#','.','.','#','.','#','.','#','.','#','.','#'},
        {'#','#','.','#','.','#','.','#','.','#','.','#'},
        {'#','.','.','.','.','.','.','.','.','#','.','#'},
        {'#','#','#','#','#','#','.','#','#','#','.','#'},
        {'#','.','.','.','.','.','.','#','.','.','.','#'},
        {'#','#','#','#','#','#','#','#','#','#','#','#'}
    };

    printf("Original Maze:\n\n");
    printMaze(maze);

    printf("\nSearching for exit...\n\n");

    if (traverseMaze(maze, 2, 0))
    {
        printf("\nExit Found!\n\n");
    }
    else
    {
        printf("\nNo Exit Found!\n\n");
    }

    printf("Final Maze:\n\n");
    printMaze(maze);

    return 0;
}

