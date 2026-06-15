#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int isValidString(const char moves[])
{
    int i;

    for (i = 0; moves[i] != '\0'; i++)
    {
        if (moves[i] != 'L' &&
            moves[i] != 'R' &&
            moves[i] != '_')
        {
            return 0;
        }
    }

    return 1;
}

int furthestDistanceFromOrigin(const char moves[])
{
    int left = 0;
    int right = 0;
    int blank = 0;
    int i;

    for (i = 0; moves[i] != '\0'; i++)
    {
        if (moves[i] == 'L')
        {
            left++;
        }
        else if (moves[i] == 'R')
        {
            right++;
        }
        else if (moves[i] == '_')
        {
            blank++;
        }
    }

    return abs(right - left) + blank;
}

int main()
{
    char moves[51];

    printf("Enter movement string (L, R, _ only): ");
    scanf("%50s", moves);

    if (!isValidString(moves))
    {
        printf("Invalid input! Only L, R, and _ are allowed.\n");
        return 1;
    }

    int distance = furthestDistanceFromOrigin(moves);

    printf("Furthest possible distance from origin: %d\n", distance);

    return 0;
}

