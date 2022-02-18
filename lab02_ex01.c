/* 
 * File:   lab02_ex01.c
 * Author: riwakaram
 *
 * Created on September 28, 2021, 10:44 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/*
 * Helper function that computes the product. Returns the sum 1 + 2 + ... + n.
 * Assumes that n > 0.
 */
int _sum(int n) {
    // base case: the sum of 1 is just 1
    if (n == 1) {
        return 1;
    }

    // recursive case: compute (1 + 2 + ... + (n-1) + n)
    return _sum(n - 1) + n;
}

/*
 * Interface for computing the sum 1 + 2 + 3 + ... + n
 * Returns -1 if n <= 0 or s is null; otherwise, stores the sum in the cell that
 * s references and returns 0.
 */
int sum(int n, int *s) {
    if (n <= 0 || s == NULL) {
        return -1;
    }

    // We know that n > 0 at this point, so we can safely call the helper
    // function

    *s = _sum(n);

    // success
    return 0;
}

int main(int argc, char** argv) {

    // test the sum function
    int s, err;
    err = sum(5, &s);
    assert(err == 0);

    // print the result to the console
    printf("%d\n", s);

    // test bad input
    err = sum(-3, &s);
    assert(err != 0);

    return (EXIT_SUCCESS);
}

