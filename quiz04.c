/* 
 * File:   quiz04.c
 * Author: riwakaram
 *
 * Created on November 9, 2021, 1:45 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * Prints an int matrix
 * Returns -1 for incorrect input and 0 for success
 */
int print_float_matrix(int row, int col, float a[row][col]) {
    if (!a || row <= 0 || col <= 0) return -1;

    int r, c;
    for (r = 0; r < row; r++) {
        for (c = 0; c < col; c++) {
            printf("%8.4f", a[r][c]);
        }
        printf("\n");
    }

    return 0;
}

/* 
 * Write a function that prints a float array
 * The function returns 0 if successful and -1 if a wrong input is provided
 */
int print_float_array(float a[], int n) {
    if (!a || n <= 0) return -1;

    int i;
    for (i = 0; i < n; i++) {
        printf("%8.4f\n", a[i]);
    }

    return 0;
}

/*
 * Gets the vectorization of a matrix
 * Returns -1 for incorrect input and 0 for success
 */
int vec(int row, int col, float a[row][col], float b[row * col]) {
    if (!a || !b || row <= 0 || col <= 0) return -1;

    int r, c, k;
    for (r = 0; r < row; r++) {
        for (c = 0; c < col; c++) {
            for (k = 0; k < row * col; k++) {
                b[k] = a[r][c];
            }
        }
    }

    return 0;
}

int main(int argc, char** argv) {

    const int row = 3, col = 2;

    float a[row][col] = {
        {5.2, -1.3},
        {0.5, 4.7},
        {-7.1, 3.4}
    };

    printf("The matrix A is:\n");
    print_float_matrix(row, col, a);

    float b[row * col];
    vec(row, col, a, b);

    printf("\nThe vector B is:\n");
    print_float_array(b, row * col);

    return (EXIT_SUCCESS);
}

