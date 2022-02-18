/* 
 * File:   matrix.h
 * Author: riwakaram
 *
 * Created on November 4, 2021, 2:04 PM
 */

#ifndef MATRIX_H
#define MATRIX_H

#ifdef __cplusplus
extern "C" {
#endif

#define ELEM(mtx, row, col) mtx->data[(col - 1) * mtx->rows + (row - 1)]

    typedef struct {
        int rows;
        int cols;
        double *data;
    } matrix;

    matrix *newMatrix(int rows, int cols);
    int printMatrix(matrix *mtx);
    int setElement(matrix *mtx, int row, int col, double value);
    int deleteMatrix(matrix *mtx);
    // int copyMatrix(matrix *dest, matrix *src);
    matrix *copyMatrix(matrix *mtx);

#ifdef __cplusplus
}
#endif

#endif /* MATRIX_H */
