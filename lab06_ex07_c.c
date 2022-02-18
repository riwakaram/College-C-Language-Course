/* 
 * File:   lab06_ex07_c.c
 * Author: riwakaram
 *
 * Created on November 26, 2021, 11:36 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "lab06.h"

int main(int argc, char** argv) {

    matrix * B = newMatrix(3, 3);
    setElement(B, 1, 3, 1.0);
    setElement(B, 2, 1, 0.25);
    setElement(B, 2, 2, 0.4);
    setElement(B, 3, 1, 3.0);
    setElement(B, 3, 2, 0.1);
    setElement(B, 3, 3, -0.3);
    printf("Matrix B:\n");
    printMatrix(B);

    matrix * col2 = getColumn(B, 2);
    printf("\nThe second column of matrix B is:\n");
    printMatrix(col2);

    matrix * row3 = getRow(B, 3);
    printf("\nThe third row of matrix B is:\n");
    printMatrix(row3);

    return (EXIT_SUCCESS);
}
