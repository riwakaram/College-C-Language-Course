/* 
 * File:   classWork210916.c
 * Author: riwakaram
 *
 * Created on September 16, 2021, 2:07 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * Recursion:
 * Function calls itself repeatedly (recursively)
 * f(n) = n! = n * (n-1) * ... * 3 * 2 * 1
 * recursive definition of factorial
 * base case: f(0) = 1 and f(1) = 1
 * recursive relationship: f(n) = n * (n-1)
 * 
 * example: 5! = f(5) = 5 * f(4)
 *                    = 5 * 4 * f(3)
 *                    = 5 * 4 * 3 * f(2)
 *                    = 5 * 4 * 3 * 2 * f(1)
 *                    = 5 * 4 * 3 * 2 * 1
 *                    = 120
 * 
 * Write a recursive function that computes and returns the factorial of
 * a positive integer
 */

unsigned long long _fact(int n) {
    // base case
    if (n == 0 || n == 1) return 1;

    return n * _fact(n - 1);
}

unsigned long long fact(int n, unsigned long long *f) {
    if (n < 0) {
        return -1; // returns an error code of -1
    }

    *f = _fact(n);
    return 0; // successful completion
}

int main(int argc, char** argv) {

    /*
        int x;
        printf("Enter a positive integer: ");
        scanf("%d", &x);
    
        int y = fact(x);
        printf("\nThe factorial of %d is %d.", x, y);
     */

    /*Print the factorial of all positive numbers up to 12*/

    /*
        int i;
        for(i = 0; i <= 20; i++){
            printf("\n%3d! = %20llu", i, fact(i));
        }
     */

    //printf("%llu", fact(-1)); //infinite loop


    int x;
    printf("Enter a positive number: ");
    scanf("%d", &x);

    unsigned long long f;

    if (fact(x, &f) == -1) {
        printf("\nERROR: factorial of negative numbers cannot be computed.");
    } else {
        printf("\nThe factorial of %d is %d.", x, f);
    }


    /*
        int a[10]; // array that is not initialized (garbage values)
        int b[10] = {0}; // array with all initial values equal to 0
        int c[10] = {1}; // first value is 1, and the rest zeroes
     */
    // Write code to initialize array a with the squares of the index

    /*
        int i;
        for(i = 0; i < 10; i++){
            a[i] = i * i;
            printf("%4d", a[i]);
        }
    
        int *p;
        p = a + 4;
    
        printf("\n%d", *p);
     */

    return (EXIT_SUCCESS);
}

