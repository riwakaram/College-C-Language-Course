/* 
 * File:   lab04_ex03.c
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
 * Copies the elements of an integer array a into an integer array b with the 
 * elements of the columns reversed
 * Returns -1 for incorrect input and 0 for success
 */
int copy_cols_reversed(int row, int col, int a[row][col], int b[row][col]) {
    if (!a || !b || row <= 0 || col <= 0) return -1;

    int r, c;
    for (r = 0; r < row; r++) {
        for (c = 0; c < col; c++) {
            b[r][c] = a[row - r - 1][c];
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

    int b[rows][cols] = {0};

    printf("The copy array of the original one with the columns reversed is: \n");
    copy_cols_reversed(rows, cols, a, b);
    print_int_array(rows, cols, b);
    printf("\n");

    return (EXIT_SUCCESS);
}

