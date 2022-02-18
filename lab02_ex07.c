/* 
 * File:   lab02_ex07.c
 * Author: riwakaram
 *
 * Created on September 28, 2021, 10:45 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* 
 * Computes the sum of two n-dimensional vectors, x and y, and stores it in 
 * vector sum. Returns 0 if successful, -1 if any of x, y, or sum is NULL and 
 * -2 if n <= 0.
 */
int vectorSum(int x[], int y[], int n, int sum[]) {
    if (!x || !y || !sum) {
        return -1;
    }
    if (n <= 0) {
        return -2;
    }

    for (int i = 0; i < n; i++) {
        sum[i] = x[i] + y[i];
    }

    // indicates success
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
        printf("%6d", x[i]);
    }

    // indicate success
    return 0;
}

int main(int argc, char** argv) {

    const int N = 15;
    int a[N], b[N], vSum[N];

    random_fill_array(a, N);
    random_fill_array(b, N);

    // printing the arrays
    printf("The first vector is:\n");
    print_int_array(a, N);
    printf("\nThe second vector is:\n");
    print_int_array(b, N);

    // computing the sum vector
    vectorSum(a, b, N, vSum);

    // printing the sum vector
    printf("\n\nThe sum  of the previous two vectors is:\n");
    print_int_array(vSum, N);

    return (EXIT_SUCCESS);
}

