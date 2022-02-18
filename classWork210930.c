/* 
 * File:   classWork210930.c
 * Author: riwakaram
 *
 * Created on September 30, 2021, 1:59 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "array1.h"

int main(int argc, char** argv) {

    const int N = 10;
    int a[N], b[N], c[2 * N];
    srand(time(0));

    random_int_array(a, N);
    random_int_array(b, N);
    zip(a, b, c, N);

    print_int_array(a, N);
    printf("\n");

    print_int_array(b, N);
    printf("\n");

    print_int_array(c, 2 * N);
    printf("\n");

    return (EXIT_SUCCESS);
}

