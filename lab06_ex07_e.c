/* 
 * File:   lab06_ex07_e.c
 * Author: riwakaram
 *
 * Created on November 26, 2021, 11:36 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "lab06.h"

int main(int argc, char** argv) {

    matrix * A = newMatrix(3, 3);
    setElement(A, 1, 1, 1.0);
    setElement(A, 1, 2, 0.25);
    setElement(A, 1, 3, -0.1);
    setElement(A, 2, 2, 0.4);
    setElement(A, 2, 3, 0.3);
    setElement(A, 3, 2, 0.1);
    setElement(A, 3, 3, -0.3);
    printf("Matrix A:\n");
    printMatrix(A);
    printf("\n");

    matrix * B = newMatrix(3, 3);
    power(A, 3, B);
    printf("Matrix B = A^3:\n");
    printMatrix(B);

    return (EXIT_SUCCESS);
}

