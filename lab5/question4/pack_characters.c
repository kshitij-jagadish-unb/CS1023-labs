#include <stdio.h>

unsigned int packCharacters( unsigned char ch1, unsigned char ch2, unsigned char ch3, unsigned char ch4) {

    unsigned int packed = ch1;

    packed = packed << 8;
    packed = packed | ch2;

    packed = packed << 8;
    packed = packed | ch3;

    packed = packed << 8;
    packed = packed | ch4;

    return packed;
}

int main(void) {

    char ch1;
    char ch2;
    char ch3;
    char ch4;

    printf("Entah the 1st character: ");
    scanf(" %c", &ch1);

    printf("Entah the 2nd character: ");
    scanf(" %c", &ch2);

    printf("Entah the 3rd character: ");
    scanf(" %c", &ch3);

    printf("Entah the 4th character: ");
    scanf(" %c", &ch4);

    unsigned int packed = packCharacters(ch1, ch2, ch3, ch4);

    printf("\n The Packed value: %u\n", packed);
    printf(" The Hexadecimal Version: %X\n", packed);

    return 0;
}

