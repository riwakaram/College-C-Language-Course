/* 
 * File:   lab02_ex08.c
 * Author: riwakaram
 *
 * Created on September 28, 2021, 10:45 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * Computes the minimum and maximum elements of the array a of length n, storing
 * them in the memory cells to which min and max, respectively, point.
 * Returns 0 if successful, -1 if one or more of a, min, or max is NULL and -2
 * if n <= 0.
 */
int minmax(int * a, int n, int * min, int * max) {
    // check if input is well-formed
    if (!a || !min || !max) {
        return -1;
    }
    if (n <= 0) {
        return -2;
    }

    // assigning m1 and m2 to the first element in the array
    int m1 = a[0], m2 = a[0];

    for (int i = 1; i < n; i++) {
        if (a[i] < m1) {
            // a[i] is even smaller than previously seen elements
            m1 = a[i];
        }
        if (a[i] > m2) {
            // a[i] is even larger than previously seen elements
            m2 = a[i];
        }
    }

    *min = m1;
    *max = m2;

    // success
    return 0;
}

/*
 * This function fill an array of size n with random values between 10 and 99
 * It returns -1 if x is a null reference or n is negative or equal to 0 and 0
 * for a success run
 */
int random_fill_array(int *x, int n) {
    // check if input is well-formed
    if (!x || n <= 0) {
        return -1;
    }

    srand(time(0));

    // filling the arrays a and b with random values between 10 and 99
    int i;
    for (i = 0; i < n; i++) {
        x[i] = (rand() % 90) + 10;
    }

    // indicate success
    return 0;
}

/*
 * This function prints an array of size n
 * It returns -1 if x is a null reference or n is negative or equal to 0 and 0 
 * for a success run
 */
int print_int_array(int *x, int n) {
    // check if input is well-formed
    if (!x || n <= 0) {
        return -1;
    }

    int i;
    for (i = 0; i < n; i++) {
        printf("%4d", x[i]);
    }

    // indicate success
    return 0;
}

int main(int argc, char** argv) {

    const int N = 15;
    int a[N], min, max;

    random_fill_array(a, N);

    // printing the array
    printf("The array is:\n");
    print_int_array(a, N);

    // ding the max and the min
    minmax(a, N, &min, &max);

    // printing the min and the max
    printf("\n\nThe minimum  of the  array is: %-4d", min);
    printf("\nThe maximum  of the  array is: %-4d", max);

    return (EXIT_SUCCESS);
}

