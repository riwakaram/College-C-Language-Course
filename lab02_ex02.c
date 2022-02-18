/* 
 * File:   lab02_ex02.c
 * Author: riwakaram
 *
 * Created on September 28, 2021, 10:44 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * Helper function that computes the product. Returns the product 
 * 1 * 2 * ... * n.
 * Assumes that n > 0.
 */
int _product(int n) {
    // base case: the product of 1 is just 1
    if (n == 1) {
        return 1;
    }

    // recursive case: compute (1 * 2 * ... * n)
    return _product(n - 1) * n;
}

/*
 * Interface for computing the product 1 * 2 * ... * n
 * Returns -1 if n <= 0 or s is null; otherwise, stores the sum in the cell that
 * s references and returns 0.
 */
int product(int n, int *s) {
    if (n <= 0 || s == NULL) {
        return -1;
    }

    // We know that n > 0 at this point, so we can safely call the helper
    // function

    *s = _product(n);

    //success
    return 0;
}

int main(int argc, char** argv) {

    // test the product function
    int p;

    if (product(5, &p) == -1) {
        printf("\nERROR: Wrong Input.");
    } else {
        printf("The product of %d is %d.", 5, p);
    }

    if (product(1, &p) == -1) {
        printf("\nERROR: Wrong Input.");
    } else {
        printf("\nThe product of %d is %d.", 1, p);
    }

    // test bad input: negative number
    if (product(-2, &p) == -1) {
        printf("\nERROR: Wrong Input.");
    } else {
        printf("\nThe product of %d is %d.", -2, p);
    }

    // test bad input: null pointer
    if (product(5, NULL) == -1) {
        printf("\nERROR: Wrong Input.");
    } else {
        printf("\nThe product of %d is %d.", 5, p);
    }

    return (EXIT_SUCCESS);
}

