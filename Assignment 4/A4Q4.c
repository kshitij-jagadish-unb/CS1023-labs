#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUITS 4
#define FACES 13
#define HAND_SIZE 5

void shuffle(int deck[SUITS][FACES])
{
    int row, col, card;

    for (card = 1; card <= 52; card++)
    {
        do
        {
            row = rand() % SUITS;
            col = rand() % FACES;
        }
        while (deck[row][col] != 0);

        deck[row][col] = card;
    }
}

void deal(const int deck[SUITS][FACES],
          int handSuits[],
          int handFaces[])
{
    int card, row, col;
    int count = 0;

    for (card = 1; card <= HAND_SIZE; card++)
    {
        for (row = 0; row < SUITS; row++)
        {
            for (col = 0; col < FACES; col++)
            {
                if (deck[row][col] == card)
                {
                    handSuits[count] = row;
                    handFaces[count] = col;
                    count++;
                }
            }
        }
    }
}

void printHand(int handSuits[], int handFaces[])
{
    const char *faces[FACES] =
    {
        "Ace","Deuce","Three","Four","Five",
        "Six","Seven","Eight","Nine","Ten",
        "Jack","Queen","King"
    };

    const char *suits[SUITS] =
    {
        "Hearts",
        "Diamonds",
        "Clubs",
        "Spades"
    };

    int i;

    for (i = 0; i < HAND_SIZE; i++)
    {
        printf("%s of %s\n",
               faces[handFaces[i]],
               suits[handSuits[i]]);
    }
}

int onePair(int handFaces[])
{
    int count[FACES] = {0};
    int i, pairs = 0;

    for (i = 0; i < HAND_SIZE; i++)
        count[handFaces[i]]++;

    for (i = 0; i < FACES; i++)
        if (count[i] == 2)
            pairs++;

    return pairs == 1;
}

int twoPairs(int handFaces[])
{
    int count[FACES] = {0};
    int i, pairs = 0;

    for (i = 0; i < HAND_SIZE; i++)
        count[handFaces[i]]++;

    for (i = 0; i < FACES; i++)
        if (count[i] == 2)
            pairs++;

    return pairs == 2;
}

int threeOfKind(int handFaces[])
{
    int count[FACES] = {0};
    int i;

    for (i = 0; i < HAND_SIZE; i++)
        count[handFaces[i]]++;

    for (i = 0; i < FACES; i++)
        if (count[i] == 3)
            return 1;

    return 0;
}

int fourOfKind(int handFaces[])
{
    int count[FACES] = {0};
    int i;

    for (i = 0; i < HAND_SIZE; i++)
        count[handFaces[i]]++;

    for (i = 0; i < FACES; i++)
        if (count[i] == 4)
            return 1;

    return 0;
}

int flush(int handSuits[])
{
    int i;

    for (i = 1; i < HAND_SIZE; i++)
    {
        if (handSuits[i] != handSuits[0])
            return 0;
    }

    return 1;
}

int straight(int handFaces[])
{
    int temp[HAND_SIZE];
    int i, j, swap;

    for (i = 0; i < HAND_SIZE; i++)
        temp[i] = handFaces[i];

    for (i = 0; i < HAND_SIZE - 1; i++)
    {
        for (j = i + 1; j < HAND_SIZE; j++)
        {
            if (temp[i] > temp[j])
            {
                swap = temp[i];
                temp[i] = temp[j];
                temp[j] = swap;
            }
        }
    }

    for (i = 1; i < HAND_SIZE; i++)
    {
        if (temp[i] != temp[i - 1] + 1)
            return 0;
    }

    return 1;
}

int main()
{
    int deck[SUITS][FACES] = {0};

    int handSuits[HAND_SIZE];
    int handFaces[HAND_SIZE];

    srand((unsigned)time(NULL));

    shuffle(deck);

    deal(deck, handSuits, handFaces);

    printf("Random Poker Hand\n\n");

    printHand(handSuits, handFaces);

    printf("\nAnalysis:\n");

    printf("One Pair: %s\n",
           onePair(handFaces) ? "YES" : "NO");

    printf("Two Pairs: %s\n",
           twoPairs(handFaces) ? "YES" : "NO");

    printf("Three of a Kind: %s\n",
           threeOfKind(handFaces) ? "YES" : "NO");

    printf("Four of a Kind: %s\n",
           fourOfKind(handFaces) ? "YES" : "NO");

    printf("Flush: %s\n",
           flush(handSuits) ? "YES" : "NO");

    printf("Straight: %s\n",
           straight(handFaces) ? "YES" : "NO");

    return 0;
}

