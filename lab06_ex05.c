/* 
 * File:   lab06_ex05.c
 * Author: riwakaram
 *
 * Created on November 25, 2021, 8:37 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "lab06.h"

int main(int argc, char** argv) {

    const int N = 5, M = 3;

    matrix *i1 = identity01(N);
    printMatrix(i1);

    printf("\n\n");

    matrix *i2 = newMatrix(M, M);
    identity02(i2);
    printMatrix(i2);

    return (EXIT_SUCCESS);
}
