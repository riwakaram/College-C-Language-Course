/* 
 * File:   classWork210909.c
 * Author: riwakaram
 *
 * Created on September 9, 2021, 2:15 PM
 */

#include <stdio.h>
#include <stdlib.h>

#define PART2

/* Write a function that swaps the values of two integers */
void swap_v1(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

void swap_v2(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(int argc, char** argv) {

#ifdef PART1    
    int a = 0xff;
    int *p; //of type pointer (holds addresses, not values)

    p = &a; //illegal to say p = 24

    printf("\nThe value of a is %d, located at %p", a, &a);
    printf("\nThe value of p is %p", p);
    printf("\nThe value of where the pointer p points is %d", *p);
    //*p means "the value where the pointer p points
    *p = 75; //the * notation indicates dereferencing
    printf("\na has become %d", a);

    float x = 3.14;
    printf("\nThe value of x is %f", x);

    int **q;
    q = &p;
    printf("\nThe value where q points is %d", **q);
    **q = -17;
    printf("\na has become %d", a);
    printf("\n*q = %p", *q);
    printf("\n&p = %p", &p);
    printf("\n&p = %p", q);
    printf("\n&q = %p", % q);
#endif

#ifdef PART2

    int x = 12, y = -5;
    printf("Before swap, x = %d and y = %d", x, y);
    swap_v2(&x, &y);
    printf("\nAfter swap, x = %d and y = %d", x, y);

#endif    

    return (EXIT_SUCCESS);
}

