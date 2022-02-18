/* 
 * File:   classWork211104.c
 * Author: riwakaram
 *
 * Created on November 4, 2021, 2:04 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

/*
 * 
 */
int main(int argc, char** argv) {

    matrix *A, *B, *P;

    A = newMatrix(2, 3);
    printMatrix(A);

    setElement(A, 1, 2, -5.5);
    printf("\n");
    printMatrix(A);

    B = copyMatrix(A);
    printf("\n");
    printMatrix(B);
    setElement(B, 2, 2, 15.3);

    P = B;
    printf("\n");
    printMatrix(P);

    deleteMatrix(A);
    deleteMatrix(B);

    return (EXIT_SUCCESS);
}

