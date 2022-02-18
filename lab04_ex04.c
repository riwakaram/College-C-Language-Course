/* 
 * File:   lab04_ex04.c
 * Author: riwakaram
 *
 * Created on November 1, 2021, 9:31 AM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * Prints an int matrix
 * Returns -1 for incorrect input and 0 for success
 */
int print_int_array(int row, int col, int a[row][col]) {
    if (!a || row <= 0 || col <= 0) return -1;

    int r, c;
    for (r = 0; r < row; r++) {
        for (c = 0; c < col; c++) {
            printf("%5d", a[r][c]);
        }
        printf("\n");
    }

    return 0;
}

/*
 * Gets the transpose of a matrix
 * Returns -1 for incorrect input and 0 for success
 */
int matrix_tranpose(int row, int col, int a[row][col], int b[col][row]) {
    if (!a || !b || row <= 0 || col <= 0) return -1;

    int r, c;
    for (r = 0; r < row; r++) {
        for (c = 0; c < col; c++) {
            b[c][r] = a[r][c];
        }
    }

    return 0;
}

int main(int argc, char** argv) {

    const int rows = 4, cols = 5;

    int a[rows][cols] = {
        {3, 8, -6, -2, 12},
        {0, 15, 7, 4, -5},
        {18, 9, 4, 5, -1},
        {1, 7, -6, 2, 1}
    };

    printf("The original array is: \n");
    print_int_array(rows, cols, a);
    printf("\n");

    int t[cols][rows] = {0};

    printf("The transpose of the original array is: \n");
    matrix_tranpose(rows, cols, a, t);
    print_int_array(cols, rows, t);
    printf("\n");

    return (EXIT_SUCCESS);
}

