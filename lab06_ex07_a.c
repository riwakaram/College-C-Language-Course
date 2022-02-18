/* 
 * File:   lab06_ex07_a.c
 * Author: riwakaram
 *
 * Created on November 25, 2021, 11:43 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "lab06.h"

int main(int argc, char** argv) {

    matrix * A = newMatrix(3, 3);
    setElement(A, 1, 1, 1.0);
    setElement(A, 2, 1, 0.25);
    setElement(A, 2, 2, 0.4);
    setElement(A, 3, 1, 3.0);
    setElement(A, 3, 2, 0.1);
    setElement(A, 3, 3, -0.3);
    printf("Matrix A:\n");
    printMatrix(A);
    printf("\nIs matrix A lower triangular? %s\n\n",
            isLowerTriangular(A) == 0 ? "True" : "False");
    
    matrix * B = newMatrix(3, 3);
    setElement(B, 1, 3, 1.0);
    setElement(B, 2, 1, 0.25);
    setElement(B, 2, 2, 0.4);
    setElement(B, 3, 1, 3.0);
    setElement(B, 3, 2, 0.1);
    setElement(B, 3, 3, -0.3);
    printf("Matrix B:\n");
    printMatrix(B);
    printf("\nIs matrix B lower triangular? %s\n",
            isLowerTriangular(B) == 0 ? "True" : "False");

    return (EXIT_SUCCESS);
}
