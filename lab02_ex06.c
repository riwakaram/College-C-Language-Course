/* 
 * File:   lab02_ex06.c
 * Author: riwakaram
 *
 * Created on September 28, 2021, 10:45 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * This function computes the dot product of two vectors and stores that value
 * in a reference.
 * It returns -1 if any of the references are null references, -2 if n is
 * negative or equal to 0 and 0 for a success run
 */
int dotProduct(int x[], int y[], int n, int *dp) {
    // check if input is well-formed
    if (x == NULL || y == NULL || dp == NULL) {
        return -1;
    }
    if (n <= 0) {
        return -2;
    }

    // compute the dot product
    *dp = 0;
    int i;
    for (i = 0; i < n; i++) {
        *dp += x[i] * y[i];
    }

    // indicate success
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
    int a[N], b[N], dotProd;

    random_fill_array(a, N);
    random_fill_array(b, N);

    // printing the arrays
    printf("The first vector is:\n");
    print_int_array(a, N);
    printf("\nThe second vector is:\n");
    print_int_array(b, N);

    // computing the dot product
    dotProduct(a, b, N, &dotProd);

    // printing the dot product
    printf("\n\nThe dot product of the previous two vectors is: %-8d", dotProd);

    return (EXIT_SUCCESS);
}

