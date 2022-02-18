/* 
 * File:   lab06_ex06.c
 * Author: riwakaram
 *
 * Created on November 25, 2021, 8:40 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "lab06.h"

int main(int argc, char** argv) {

    matrix *mtx1 = newMatrix(3, 3);
    setElement(mtx1, 1, 1, 1.0);
    setElement(mtx1, 1, 2, 0.25);
    setElement(mtx1, 1, 3, -0.1);
    setElement(mtx1, 2, 2, 0.4);
    setElement(mtx1, 2, 3, 0.3);
    setElement(mtx1, 3, 2, 0.1);
    setElement(mtx1, 3, 3, -0.3);
    printf("Matrix 1:\n");
    printMatrix(mtx1);
    printf("Is matrix 1 a square matrix? %s\n", isSquare(mtx1) == 1 ? "True" : "False");
    printf("Is matrix 1 a diagonal matrix? %s\n",
            isDiagonal(mtx1) == 0 ? "True" : "False");
    printf("\n");

    matrix *mtx2 = newMatrix(3, 4);
    setElement(mtx2, 1, 1, 0.5);
    setElement(mtx2, 2, 2, 2.0);
    setElement(mtx2, 3, 3, 1.0);
    printf("Matrix 2:\n");
    printMatrix(mtx2);
    printf("Is matrix 2 a square matrix? %s\n", isSquare(mtx2) == 1 ? "True" : "False");
    printf("Is matrix 2 a diagonal matrix? %s\n",
            isDiagonal(mtx2) == 0 ? "True" : "False");
    printf("\n");

    matrix *mtx3 = newMatrix(3, 3);
    setElement(mtx3, 1, 1, 0.5);
    setElement(mtx3, 2, 2, 2.0);
    setElement(mtx3, 3, 3, 1.0);
    printf("Matrix 3:\n");
    printMatrix(mtx3);
    printf("Is matrix 3 a square matrix? %s\n", isSquare(mtx3) == 1 ? "True" : "False");
    printf("Is matrix 3 a diagonal matrix? %s\n",
            isDiagonal(mtx3) == 0 ? "True" : "False");

    return (EXIT_SUCCESS);
}
