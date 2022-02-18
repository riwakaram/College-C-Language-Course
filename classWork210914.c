/* 
 * File:   classWork210914.c
 * Author: riwakaram
 *
 * Created on September 14, 2021, 2:02 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*
 * 
 */
int main(int argc, char** argv) {

    int a = 65535;

    printf("\n%8x", a);
    printf("\n%d", INT_MAX);
    printf("\n%u", UINT_MAX);
    printf("\n%llu", ULLONG_MAX);
    printf("\n%u", -1);
    printf("\n%llu", (unsigned long long) (-1));
    printf("\n%lu", (unsigned long) (-1));

    int b = 0xffff;

    printf("\n%d", b);

    int c = 0x0061;

    printf("\n%c", c);

    return (EXIT_SUCCESS);
}

