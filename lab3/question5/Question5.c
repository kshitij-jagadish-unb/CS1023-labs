#include <stdio.h>

int main(void) {

    int n = 0;
    int i =0;

    long long first = 0;
    long long second = 1;
    long long next;

    printf("How many Fibonacci numbers you looking for? ");
    scanf("%d", &n);

    while (i <= n) {
        
        printf("%lld\n", first);

        next = first + second;
        first = second;
        second = next;

        i = i + 1;
    }


    return 0;
}