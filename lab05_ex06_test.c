/* 
 * File:   lab05_ex06_test.c
 * Author: riwakaram
 *
 * Created on November 10, 2021, 9:35 AM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * This function prints an integer in binary form
 */
void PrintInBinary(unsigned int decNum) {
    int i = 0;
    unsigned int highestOne = 1 << (sizeof (unsigned int)*8 - 1);
    for (i = 0; i < sizeof (int)*8; i++) {
        printf("%d", (decNum & (highestOne >> i))>> (64 - i - 1));
    }
    printf("\n");
}

void PrintInBinary_test(unsigned int decNum) {
    int i = 0;
    unsigned int highestOne = 1 << (sizeof (unsigned int)*8 - 1);

    for (i = 0; i < sizeof (int)*8; i++) {
        printf("\n%2d: (", i);
        PrintInBinary(decNum);
        printf(" & ");
        PrintInBinary(highestOne >> i);
        printf(") >> ");
        PrintInBinary(highestOne - i - 1);
        printf(" ");
        printf("%d", (decNum & (highestOne >> i)) >> (highestOne - i - 1));
    }
    printf("\n");
}

int main(int argc, char** argv) {

    unsigned int a = 5, b = 120, c = 1000342;
    //PrintInBinary_test(a);
    /*
        PrintInBinary(a);
        PrintInBinary(b);
        PrintInBinary(c);
     */

    printf("%u", (10 << 33));

    return (EXIT_SUCCESS);
}
