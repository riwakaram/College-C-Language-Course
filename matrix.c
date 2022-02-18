#include <stdlib.h>
#include <stdio.h>
#include "matrix.h"

/*
 * Creates a new matrix of given dimensions and returns pointer to 
 * the location of the matrix
 */
matrix *newMatrix(int rows, int cols) {
    if (rows <= 0 || cols <= 0) return NULL;

    matrix *m = (matrix *) malloc(sizeof (matrix));

    m->rows = rows;
    m->cols = cols;

    m->data = (double *) malloc(rows * cols * sizeof (double));

    int i;
    for (i = 0; i < rows * cols; i++) {
        m->data[i] = 0;
    }

    return m;
}

int printMatrix(matrix *mtx) {
    if (mtx == NULL) return -1;

    int r, c;
    for (r = 1; r <= mtx->rows; r++) {
        for (c = 1; c <= mtx->cols; c++) {
            printf("%10.4f", ELEM(mtx, r, c));
        }
        printf("\n");
    }

    return 0;
}

int setElement(matrix *mtx, int row, int col, double value) {
    if (mtx == NULL || row <= 0 || col <= 0 ||
            col > mtx->cols || row > mtx->rows) return -1;

    ELEM(mtx, row, col) = value;

    return 0;
}

int deleteMatrix(matrix *mtx) {
    if (!mtx) return -1;

    free(mtx->data);
    free(mtx);

    return 0;
}

matrix *copyMatrix(matrix *mtx) {
    if (!mtx) return NULL;

    matrix *dest = newMatrix(mtx->rows, mtx->cols);

    int r, c;
    for (r = 1; r <= mtx->rows; r++) {
        for (c = 1; c <= mtx->cols; c++) {
            ELEM(dest, r, c) = ELEM(mtx, r, c);
        }
    }

    return dest;
}
