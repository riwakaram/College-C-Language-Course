/* 
 * File:   lab05_ex05.c
 * Author: riwakaram
 *
 * Created on November 10, 2021, 9:25 AM
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {

    unsigned char b = 'z';
    int n;

    printf("%c --> %d\n", b, b);

    n = 1;
    b &= ~(1 << n);
    printf("%c --> %d\n", b, b);

    n = 3;
    b &= ~(1 << n);
    printf("%c --> %d\n", b, b);

    n = 5;
    b &= ~(1 << n);
    printf("%c --> %d\n", b, b);

    return (EXIT_SUCCESS);
}

