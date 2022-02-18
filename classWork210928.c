/* 
 * File:   classWork210928.c
 * Author: riwakaram
 *
 * Created on September 28, 2021, 2:08 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * Write a function that takes two arrays and their sizes and 
 * copies one into another in reverse order
 * The function returns 0 if successful and -1 if a wrong input is provided
 * 
 *                   s
 * 0 1 2 3 4 5 6 7 8 9
 * d
 */

/*int copy_reversed(int source[], int dest[], int n) {
    if (!source || !dest || n <= 0) {
        return -1;
    }

    int s, d;

    for (s = 0, d = n - 1; s < n; s++, d--) { // or d >= 0
        dest[d] = source[s];
    }

    return 0;
}
 */

int copy_reversed(int *source, int *dest, int n) {
    if (!source || !dest || n <= 0) {
        return -1;
    }

    int i;

    for (i = 0; i < n; i++) {
        *(dest + n - i - 1) = *source;
        source++;
    }

    /*   s                  
     * 0 1 2 3 4 5 6 7 8 9
     * d               * 
     */

    return 0;
}

/* Write a function that prints an integer array, ten on each line
 * The function returns 0 if successful and -1 if a wrong input is provided
 */
int print_int_array(int a[], int n) {
    if (!a || n <= 0) {
        return -1;
    }

    int i;
    for (i = 0; i < n; i++) {
        printf("%4d", a[i]);
        if ((i + 1) % 10 == 0) {
            printf("\n");
        }
    }

    return 0;
}

/*
 * Write a function that takes an array of size n, and fill the array with
 * random numbers in the range [0, 999]
 * The function returns 0 if successful and -1 if a wrong input is provided
 */
int random_int_array(int a[], int n) {
    if (!a || n <= 0) {
        return -1;
    }

    int i;
    for (i = 0; i < n; i++) {
        // rand returns a random integer in [0, 32767]
        a[i] = rand() % 1000;
    }

    return 0;
}

/* 
 * in rand, the first number is called the seed
 */

int main(int argc, char** argv) {

    const int N = 150;
    int x[N], y[N];

    srand(time(0));

    int *p = y;

    if (random_int_array(x, N) == -1) {
        printf("ERROR: Bad input in function random_int_array. Exiting...\n");
        return (EXIT_FAILURE);
    }

    if (print_int_array(x, N) == -1) {
        printf("ERROR: Bad input in function print_int_array. Exiting...\n");
        return (EXIT_FAILURE);
    }

    if (copy_reversed(x, p, N) == -1) {
        printf("ERROR: Bad input in function copy_reversed. Exiting...\n");
        return (EXIT_FAILURE);
    }

    printf("\n\n");

    if (print_int_array(p, N) == -1) {
        printf("ERROR: Bad input in function print_int_array. Exiting...\n");
        return (EXIT_FAILURE);
    }

    return (EXIT_SUCCESS);
}

