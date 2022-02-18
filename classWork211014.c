/* 
 * File:   classWork211014.c
 * Author: riwakaram
 *
 * Created on October 14, 2021, 1:55 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * Write a function that prints an int matrix
 * Return 0 if successful, -1 if the array is NULL
 */
int print_int_matrix(int row, int col, int a[row][col]) {
    if (a == NULL || row <= 0 || col <= 0) return -1;

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
 * Write a function that computes and returns the sum of the values on the 
 * perimeter of an int matrix
 * Return 0 if successful, -1 for a NULL pointer
 */
int perimeter(int row, int col, int a[row][col], int *per) {
    if (a == NULL || row <= 0 || col <= 0) return -1;

    *per = 0;
    int r, c;
    for (r = 0; r < row; r++) {
        for (c = 0; c < col; c++) {
            if (r == 0 || r == (row - 1) || c == 0 || c == (col - 1)) {
                *per += a[r][c];
            }
        }
    }

    return 0;
}

/*
 * Write a function that creates a matrix of squares of the sum of the indices 
 * of rows and columns
 * 
 *      0  1  2  3  4  5 
 * -----------------------
 *  0 | 0  1  4  9 16 25
 *  1 | 1  4  9 16 25 36
 *  2 | 4  9 16 25 36 49
 * 
 */
int squares(int row, int col, int a[row][col]) {
    if (a == NULL || row <= 0 || col <= 0) return -1;

    int r, c;
    for (r = 0; r < row; r++) {
        for (c = 0; c < col; c++) {
            a[r][c] = (r + c) * (r + c);
        }
    }

    return 0;
}

int main(int argc, char** argv) {

    const int rows = 5, cols = 9;

    /*
     * 2D arrays (matrix algebra)
     */
    int m1[rows][cols] = {
        {3, -2, 7, 8},
        {-1, 0, 4, 9},
        {2, 5, -3, 6}
    };

    print_int_matrix(rows, cols, m1);

    int p;
    perimeter(rows, cols, m1, &p);
    printf("\n\nThe sum of the values on the perimeter is %d", p);

    int m2[rows][cols];
    squares(rows, cols, m2);
    printf("\n\n");
    print_int_matrix(rows, cols, m2);

    return (EXIT_SUCCESS);
}

