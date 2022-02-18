/* 
 * File:   main.c
 * Author: riwakaram
 *
 * Created on September 4, 2021, 11:03 AM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {

    float pi = 3.14159;

    printf("pi = %.2f\n", pi);
    printf("The size of pi is %lu bytes\n", sizeof (pi));
    printf("The address of pi is %p", &pi);

    int a = 5;

    printf("\n\na = %d\n", a);
    printf("The size of a is %lu bytes\n", sizeof (a));
    printf("The address of a is %p", &a);

    short int b = -7;

    printf("\n\nb = %hd\n", b);
    printf("The size of b is %lu bytes\n", sizeof (b));
    printf("The address of b is %p", &b);

    char c = 100;

    printf("\n\nc = %d\n", c);
    printf("The size of c is %lu bytes\n", sizeof (c));
    printf("The address of c is %p", &c);

    return (EXIT_SUCCESS);
}

