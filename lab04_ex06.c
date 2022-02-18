/* 
 * File:   lab04_ex06.c
 * Author: riwakaram
 *
 * Created on November 1, 2021, 10:23 AM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * Prints an int matrix
 * Returns -1 for invalid input and 0 for success
 */
int print_int_matrix(int row, int col, int a[row][col]) {
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
 * Multiplies two matrices A and B, and puts the result in a matrix C
 * Returns -1 for invalid input and 0 for success
 */
int matrix_multiplication(int m, int n, int p, int a[m][n], int b[n][p], int c[m][p]) {
    if (!a || !b || !c || m <= 0 || n <= 0 || p <= 0) return -1;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            c[i][j] = 0;
            for (int k = 0; k < n; k++) {
                c[i][j] += (a[i][k] * b[k][j]);
            }
        }
    }

    return 0;
}

int main(int argc, char** argv) {

    const int m = 4, n = 3, p = 5;

    int a[m][n] = {
        {2, 3, 4},
        {3, 4, 5},
        {1, 2, 3},
        {0, 3, 7}
    };
    printf("The first matrix is: \n");
    print_int_matrix(m, n, a);

    int b[n][p] = {
        {0, 2, 8, 3, 4},
        {3, 6, 4, 7, 5},
        {1, 6, 2, 5, 3},
    };
    printf("\nThe second matrix is: \n");
    print_int_matrix(n, p, b);

    int c[m][p];
    matrix_multiplication(m, n, p, a, b, c);
    printf("\nThe multiplication matrix of the previous two is: \n");
    print_int_matrix(m, p, c);

    int d[m][p] = {
        {5, 3, 9, 2, 5},
        {7, 0, 1, 2, 6},
        {0, 4, 6, 5, 8},
        {5, 6, 8, 2, 9}
    };
    printf("\nThe third matrix is: \n");
    print_int_matrix(m, p, d);

    int e[p][n] = {
        {5, 3, 9},
        {7, 0, 1},
        {0, 4, 6},
        {5, 3, 2},
        {0, 1, 6}
    };
    printf("\nThe fourth matrix is: \n");
    print_int_matrix(p, n, e);

    int f[m][n];
    matrix_multiplication(m, p, n, d, e, f);
    printf("\nThe multiplication matrix of the previous two is: \n");
    print_int_matrix(m, n, f);

    return (EXIT_SUCCESS);
}

