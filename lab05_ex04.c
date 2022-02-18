/* 
 * File:   lab05_ex04.c
 * Author: riwakaram
 *
 * Created on November 10, 2021, 9:04 AM
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {

    unsigned char a = 'a';
    int n;

    printf("%c --> %d\n", a, a);

    n = 1;
    a |= (1 << n);
    printf("%c --> %d\n", a, a);

    n = 2;
    a |= (1 << n);
    printf("%c --> %d\n", a, a);

    n = 3;
    a |= (1 << n);
    printf("%c --> %d\n", a, a);

    return (EXIT_SUCCESS);
}

