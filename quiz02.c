/* 
 * File:   quiz02.c
 * Author: riwakaram
 *
 * Created on October 5, 2021, 12:34 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "array1.h"
#include <time.h>

/*
 * Computes the norm of vector a of dimension n and writes the norm to where l
 * points. Returns 0, unless a or l is NULL, or if n is positive in which case,
 * returns 1.
 */
int norm(int *a, int n, float *l) {
    if (!a || !l || n <= 0) {
        return 1;
    }

    int j = 0;

    for (int i = 0; i < n; i++) {
        j += (a[i] * a[i]);
    }

    *l = sqrt(j);

    return 0;
}

int main(int argc, char** argv) {

    const int N = 5; // Euclidean space dimension

    int a[N]; //vector a in N-dimensional Euclidean space
    float mag; //will be used to hold the magnitude of a vector

    srand(time(0)); // seed the random number generation system

    //generate a vector of random component values
    if (random_int_array(a, N) == -1) {
        printf("ERROR in function random_int_array. Exiting... \n");
        return (EXIT_FAILURE);
    }

    // print the vector
    printf("The %d-dimensional vector is:\t[", N);
    if (print_int_array(a, N) == -1) {
        printf("ERROR in function print_int_array. Exiting...\n");
        return (EXIT_FAILURE);
    }
    printf("]");

    // compute the norm (magnitude) of the vector
    if (norm(a, N, &mag) == -1) {
        printf("ERROR in function norm. Exiting...\n");
        return (EXIT_FAILURE);
    }

    // print the norm
    printf("\nThe norm of this function is %f", mag);


    return (EXIT_SUCCESS);
}

