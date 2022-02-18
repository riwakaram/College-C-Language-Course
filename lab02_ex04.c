/* 
 * File:   lab02_ex04.c
 * Author: riwakaram
 *
 * Created on September 28, 2021, 10:44 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * Sums the elements of a, an array of length len, and writes the sum to where 
 * sum references. Returns 0, unless a or sum is NULL or len is negative or 0,
 * in which case returns -1.
 */
int sumArray(int *a, int len, int *sum) {
    if (!a || !sum || len <= 0) {
        return -1;
    }

    *sum = 0; // initializing sum to zero so we can add to it the elements of a

    for (int i = 0; i < len; i++) {
        *sum += a[i];
    }

    // success
    return 0;
}

int main(int argc, char** argv) {

    srand(time(0));

    for (int i = 0; i < 15; i++) {
        int n = rand() % 10;

        int s = 0, a[n];

        for (int j = 0; j < n; j++) {
            a[j] = rand() % 10;
            printf("%-4d", a[j]);
        }

        int r = sumArray(a, n, &s);

        if (r == -1) {
            printf("\nERROR: Wrong Input");
        } else {
            printf("\nThe sum of the elements of this array is: %4d", s);
        }

        printf("\nThe return value of the function sumArray is: %2d\n\n", r);
    }

    return (EXIT_SUCCESS);
}

