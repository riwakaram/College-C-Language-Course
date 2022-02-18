/* 
 * File:   quiz06.c
 * Author: riwakaram
 *
 * Created on November 30, 2021, 2:35 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "lab06.h"

int getSumOfRow(matrix * m, int row, double * sum) {
    if (!m) return -1;
    if (row <= 0 || row > m->rows) return -2;

    *sum = 0;
    int c;
    for (c = 1; c <= m->cols; c++) {
        *sum += ELEM(m, row, c);
    }

    return 0;
}

int main(int argc, char** argv) {

    matrix * m = newMatrix(3, 3);
    setElement(m, 1, 1, 1.0);
    setElement(m, 1, 2, 0.25);
    setElement(m, 1, 3, -0.1);
    setElement(m, 2, 2, 0.4);
    setElement(m, 2, 3, 0.3);
    setElement(m, 3, 2, 0.1);
    setElement(m, 3, 3, -0.3);
    printf("Matrix m:\n");
    printMatrix(m);

    double sum;
    double *p = &sum;
    int row = 2;
    getSumOfRow(m, row, p);

    printf("\nThe sum of row %d is: %8.4f", row, sum);

    return (EXIT_SUCCESS);
}

