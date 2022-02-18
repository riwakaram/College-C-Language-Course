/* 
 * File:   lab06_ex07_f.c
 * Author: riwakaram
 *
 * Created on November 26, 2021, 11:37 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "lab06.h"

#define PART_2

int main(int argc, char** argv) {

#ifdef PART_1

    int i, j, k, n;
    float A[20][20], c, x[10], sum = 0.0;

    printf("Enter the order of the matrix: ");
    scanf("%d", &n);
    printf("\nEnter the elements of the augmented matrix row-wise:\n\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= (n + 1); j++) {
            printf("A[%d][%d] : ", i, j);
            scanf("%f", &A[i][j]);
        }
    }

    for (j = 1; j <= n; j++) {
        // loop for the generation of upper triangular matrix
        for (i = 1; i <= n; i++) {
            if (i > j) {
                c = A[i][j] / A[j][j];
                for (k = 1; k <= n + 1; k++) {
                    A[i][k] = A[i][k] - c * A[j][k];
                }
            }
        }
    }

    x[n] = A[n][n + 1] / A[n][n];

    // this loop is for backward substitution
    for (i = n - 1; i >= 1; i--) {
        sum = 0;
        for (j = i + 1; j <= n; j++) {
            sum = sum + A[i][j] * x[j];
        }
        x[i] = (A[i][n + 1] - sum) / A[i][i];
    }

    printf("\nThe solution is: \n");

    for (i = 1; i <= n; i++) {
        printf("\nx%d = %10.4f\t", i, x[i]);
        // x1, x2, x3 are the required solutions
    }

#endif

#ifdef PART_2

    int n, i, j;
    printf("Enter the order of the matrix: ");
    scanf("%d", &n);
    matrix * mtx = newMatrix(n, n + 1);
    printf("\nEnter the elements of the augmented matrix row-wise:\n\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= (n + 1); j++) {
            float temp;
            printf("A[%d][%d] : ", i, j);
            scanf("%f", &temp);
            ELEM(mtx, i, j) = temp;
        }
    }

    printf("\nThe augmented matrix is:\n");
    printMatrix(mtx);
    matrix * sol = newMatrix(n, 1);
    GaussianElimination(n, mtx, sol);
    printf("\nThe solution is: \n");
    printMatrix(sol);

#endif

    return (EXIT_SUCCESS);
}
