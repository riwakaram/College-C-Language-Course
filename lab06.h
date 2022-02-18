/* 
 * File:   lab06.h
 * Author: riwakaram
 *
 * Created on November 25, 2021, 07:01 PM
 */

#pragma once

#include <stdlib.h>

#ifndef LAB06_H
#define LAB06_H

#ifdef __cplusplus
extern "C" {
#endif

#define ELEM(mtx, row, col) mtx->data[(col - 1) * mtx->rows + (row - 1)]

    typedef struct {
        int rows;
        int cols;
        double *data;
    } matrix;

    /* 
     * Creates a ‘‘rows by cols’’ matrix with all values 0.
     * Returns NULL if rows <= 0 or cols <= 0 and otherwise a * pointer 
     * to the new matrix.
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

    /*
     * Copies a matrix.
     * Returns NULL if mtx is NULL.
     */
    matrix *copyMatrix(matrix * mtx) {
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

    /* 
     * Deletes a matrix.
     * Returns 0 if successful and -1 if mtx * is NULL.
     */
    int deleteMatrix(matrix * mtx) {
        if (!mtx) return -1;

        free(mtx->data);
        free(mtx);

        return 0;
    }

    /* 
     * Sets the (row, col) element of mtx to val.
     * Returns 0 if successful, -1 if mtx is NULL,
     * and -2 if row or col are outside of the dimensions of mtx.
     */
    int setElement(matrix * mtx, int row, int col, double val) {
        if (!mtx || row <= 0 || col <= 0) return -1;
        if (col > mtx->cols || row > mtx->rows) return -2;

        ELEM(mtx, row, col) = val;

        return 0;
    }

    /* 
     * Sets the reference val to the value of the (row, col) element of mtx.
     * Returns 0 if successful, -1 if either mtx or val is NULL,
     * and -2 if row or col are outside of the dimensions of mtx.
     */
    int getElement(matrix * mtx, int row, int col, double * val) {
        if (!mtx || !val || row <= 0 || col <= 0) return -1;
        if (col > mtx->cols || row > mtx->rows) return -2;

        *val = ELEM(mtx, row, col);

        return 0;
    }

    /* 
     * Sets the reference n to the number of rows of mtx.
     * Returns 0 if successful and -1 if mtx or n is NULL.
     */
    int nRows(matrix * mtx, int * n) {
        if (!mtx || !n) return -1;

        *n = mtx->rows;

        return 0;
    }

    /* 
     * Sets the reference n to the number of columns of mtx.
     * Returns 0 if successful and -1 if mtx or n is NULL.
     */
    int nCols(matrix * mtx, int * n) {
        if (!mtx || !n) return -1;

        *n = mtx->cols;

        return 0;
    }

    /* 
     * Prints the matrix to stdout.
     * Returns 0 if successful and -1 if mtx is NULL.
     */
    int printMatrix(matrix * mtx) {
        if (!mtx) return -1;

        int r, c;
        for (r = 1; r <= mtx->rows; r++) {
            for (c = 1; c <= mtx->cols; c++) {
                printf("%10.4f", ELEM(mtx, r, c));
            }
            printf("\n");
        }

        return 0;
    }

    /* 
     * Writes the transpose of matrix in into matrix out.
     * Returns 0 if successful, -1 if either in or out is NULL,
     * and -2 if the dimensions of in and out are incompatible.
     */
    int transpose(matrix * in, matrix * out) {
        if (!in || !out) return -1;
        if (in->rows != out->cols || in->cols != out->rows) return -2;

        int r, c;
        for (r = 1; r <= in->rows; r++) {
            for (c = 1; c <= in->cols; c++) {
                ELEM(out, c, r) = ELEM(in, r, c);
            }
        }

        return 0;
    }

    /* 
     * Writes the sum of matrices mtx1 and mtx2 into matrix sum.
     * Returns 0 if successful, -1 if any of the matrices are NULL,
     * and -2 if the dimensions of the matrices are incompatible.
     */
    int sum(matrix * mtx1, matrix * mtx2, matrix * sum) {
        if (!mtx1 || !mtx2 || !sum) return -1;
        if (mtx1->rows != mtx2->rows
                || mtx1->rows != sum->rows
                || mtx1->cols != mtx2->cols
                || mtx1->cols != sum->cols) return -2;

        int r, c;
        for (r = 1; r <= sum->rows; r++) {
            for (c = 1; c <= sum->cols; c++) {
                ELEM(sum, r, c) = ELEM(mtx1, r, c) + ELEM(mtx2, r, c);
            }
        }

        return 0;
    }

    /* 
     * Writes the product of matrices mtx1 and mtx2 into matrix prod. 
     * Returns 0 if successful, -1 if any of the matrices are NULL, 
     * and -2 if the dimensions of the matrices are incompatible.
     */
    int product(matrix * mtx1, matrix * mtx2, matrix * prod) {
        if (!mtx1 || !mtx2 || !prod) return -1;
        if (mtx1->cols != mtx2->rows
                || mtx1->rows != prod->rows
                || mtx2->cols != prod->cols) return -2;

        int r, c, k;
        for (c = 1; c <= mtx2->cols; c++) {
            for (r = 1; r <= mtx1->rows; r++) {
                ELEM(prod, r, c) = 0;
                for (k = 1; k <= mtx1->cols; k++) {
                    ELEM(prod, r, c) += ELEM(mtx1, r, k) * ELEM(mtx2, k, c);
                }
            }
        }

        return 0;
    }

    /* 
     * Writes the dot product of vectors v1 and v2 into reference prod.
     * Returns 0 if successful, -1 if any of v1, v2, or prod are NULL,
     * -2 if either matrix is not a vector,and -3 if the vectors are 
     * of incompatible dimensions.
     */
    int dotProduct(matrix * v1, matrix * v2, double * prod) {
        if (!v1 || !v2 || !prod) return -1;
        if (v1->cols != 1 || v2->cols != 1) return -2;
        if (v1->rows != v2->rows) return -3;

        int r;
        *prod = 0;
        for (r = 1; r <= v1->rows; r++) {
            *prod += ELEM(v1, r, 1) * ELEM(v2, r, 1);
        }

        return 0;
    }

    /*
     * Returns an identity matrix of size n by n.
     * Returns NULL if n <= 0.
     */
    matrix * identity01(int n) {
        if (n <= 0) return NULL;
        matrix * m = newMatrix(n, n);
        int i;

        for (i = 1; i <= n; i++) {
            ELEM(m, i, i) = 1.0;
        }

        return m;
    }

    /*
     * Takes a reference of type matrix and turns it to an identity matrix.
     * Returns 0 if successful, -1 if m is NULL or if m is not a square matrix.
     */
    int identity02(matrix * m) {
        if (!m || m->rows != m->cols) return -1;

        int r, c;
        for (c = 1; c <= m->cols; c++) {
            for (r = 1; r <= m->rows; r++) {
                if (r == c) {
                    ELEM(m, r, c) = 1.0;
                } else {
                    ELEM(m, r, c) = 0.0;
                }
            }
        }

        return 0;
    }

    /*
     * Returns whether a matrix is square or not
     */
    int isSquare(matrix *mtx) {
        return mtx && mtx->rows == mtx->cols;
    }

    /*
     * Returns whether a given matrix is a diagonal matrix, that is, 
     * square and 0 everywhere except possibly on the diagonal.
     */
    int isDiagonal(matrix * mtx) {
        if (!isSquare(mtx)) return -1;

        int r, c;
        for (c = 1; c <= mtx->cols; c++) {
            for (r = 1; r <= mtx->rows; r++) {
                // if the element is not on the diagonal and not 0
                if (r != c && ELEM(mtx, r, c) != 0.0) {
                    // then the matrix is not diagonal
                    return -1;
                }
            }
        }

        return 0;
    }

    /*
     * Returns whether a given matrix is upper triangular,
     * that is, square and with all 0s below the diagonal.
     */
    int isUpperTriangular(matrix * mtx) {
        if (!isSquare(mtx)) return -1;

        int r, c;
        // looks at positions below the diagonal
        for (c = 1; c <= mtx->cols; c++) {
            for (r = c + 1; r <= mtx->rows; r++) {
                if (ELEM(mtx, r, c) != 0.0) {
                    return -1;
                }
            }
        }

        return 0;
    }

    /*
     * Returns whether a given matrix is lower triangular,
     * that is, square and with all 0s above the diagonal.
     */
    int isLowerTriangular(matrix * mtx) {
        if (!isSquare(mtx)) return -1;

        int r, c;
        // looks at positions above the diagonal
        for (r = 1; r <= mtx->rows; r++) {
            for (c = r + 1; c <= mtx->cols; c++) {
                if (ELEM(mtx, r, c) != 0.0) {
                    return -1;
                }
            }
        }

        return 0;
    }

    /* 
     * Return 0 if mtx is square and symmetric and -1 otherwise 
     * (including if mtx is NULL).
     */
    int symmetric(matrix * mtx) {
        if (!mtx || !isSquare(mtx)) return -1;

        int r, c;
        for (r = 1; r <= mtx->rows; r++) {
            for (c = r + 1; c <= mtx->cols; c++) {
                if (ELEM(mtx, r, c) != ELEM(mtx, c, r)) {
                    return -1;
                }
            }
        }

        return 0;
    }

    /*
     * Returns column col of mtx as a new vector.
     * Returns NULL if mtx is NULL or col is inconsistent with mtx’s dimensions.
     */
    matrix * getColumn(matrix * mtx, int col) {
        if (!mtx || col <= 0 || col > mtx->cols) return NULL;

        matrix * v = newMatrix(mtx->rows, 1);

        int r;
        for (r = 1; r <= mtx->rows; r++) {
            setElement(v, r, 1, ELEM(mtx, r, col));
        }

        return v;
    }

    /*
     * Returns row row of mtx as a row vector.
     * Returns NULL if mtx is NULL or row is inconsistent with mtx’s dimensions.
     */
    matrix * getRow(matrix * mtx, int row) {
        if (!mtx || row <= 0 || row > mtx->rows) return NULL;

        matrix * v = newMatrix(1, mtx->cols);

        int c;
        for (c = 1; c <= mtx->cols; c++) {
            setElement(v, 1, c, ELEM(mtx, row, c));
        }

        return v;
    }

    /*
     * Constructs a diagonal matrix from a given vector.
     * Returns 0 if successful and -1 if either v or mtx are NULL 
     * or v is not a vector, or v->row is inconsistent with mtx’s dimensions,
     * or mtx is not a square matrix.
     */
    int diagonal(matrix * v, matrix * mtx) {
        if (!v || !mtx || v->cols > 1 || v->rows != mtx->rows
                || mtx->cols != mtx->rows) return -1;

        int row, col;
        for (col = 1; col <= mtx->cols; col++) {
            for (row = 1; row <= mtx->rows; row++) {
                if (row == col) {
                    ELEM(mtx, row, col) = ELEM(v, col, 1);
                } else {
                    ELEM(mtx, row, col) = 0.0;
                }
            }
        }

        return 0;
    }

    /*
     * Sets each element of mtx to the product of that element with s.
     * Returns -1 if mtx is NULL and 0 otherwise.
     */
    int scalarProduct(double s, matrix * mtx) {
        if (!mtx) return -1;

        int r, c;
        for (r = 1; r <= mtx->rows; r++) {
            for (c = 1; c <= mtx->cols; c++) {
                ELEM(mtx, r, c) *= s;
            }
        }

        return 0;
    }

    /* 
     * Writes the pow’th power of square matrix mtx into out.
     * Returns 0 if successful, -1 if mtx or out is NULL, 
     * -2 if mtx is not square, and -3 if pow < 0.
     */
    int power(matrix * mtx, int pow, matrix * out) {
        if (!mtx || !out) return -1;
        if (!isSquare(mtx)) return -2;

        if (pow < 0) {
            return -3;
        } else if (pow == 0) {
            identity02(out);
            return 0;
        } else if (pow == 1) {
            int r, c;
            for (r = 1; r <= mtx->rows; r++) {
                for (c = 1; c <= mtx->cols; c++) {
                    ELEM(out, r, c) = ELEM(mtx, r, c);
                }
            }
            return 0;
        }

        int p;
        matrix * temp = copyMatrix(mtx);
        for (p = 1; p < pow; p++) {
            product(mtx, temp, out);
            temp = copyMatrix(out);
        }

        return 0;
    }

    /*
     * Gaussian Elimination
     */
    int GaussianElimination(int n, matrix * mtx, matrix * sol) {
        if (!mtx || !sol || n <= 0) return -1;
        if (mtx->rows != (mtx->cols - 1)) return -2;
        if (sol->cols != 1 || sol->rows != mtx->rows) return -3;

        int i, j, k;
        float c, sum;

        for (j = 1; j <= n; j++) {
            // loop for the generation of upper triangular matrix
            for (i = 1; i <= n; i++) {
                if (i > j) {
                    c = ELEM(mtx, i, j) / ELEM(mtx, j, j);
                    for (k = 1; k <= n + 1; k++) {
                        ELEM(mtx, i, k) = ELEM(mtx, i, k) - c * ELEM(mtx, j, k);
                    }
                }
            }
        }

        ELEM(sol, n, 1) = ELEM(mtx, n, n + 1) / ELEM(mtx, n, n);

        for (i = n - 1; i >= 1; i--) {
            // this loop is for backward substitution
            sum = 0;
            for (j = i + 1; j <= n; j++) {
                sum = sum + ELEM(mtx, i, j) * ELEM(sol, j, 1);
            }
            ELEM(sol, i, 1) = (ELEM(mtx, i, n + 1) - sum) / ELEM(mtx, i, i);
        }

        return 0;
    }


#ifdef __cplusplus
}
#endif

#endif /* LAB06_H */
