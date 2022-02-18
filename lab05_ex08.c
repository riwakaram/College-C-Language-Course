/* 
 * File:   lab05_ex08.c
 * Author: riwakaram
 *
 * Created on November 10, 2021, 4:33 PM
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {

    if (argc != 3) {
        printf("ERROR: you should provide three arguments. Exiting...\n");
        return (EXIT_FAILURE);
    }

    int m, n;
    if (sscanf(argv[1], "%d", &m) != 1 || sscanf(argv[2], "%d", &n) != 1) {
        printf("ERROR: you should enter two integer values. Exiting...\n");
        return (EXIT_FAILURE);
    }

    if (m <= 0 || n <= 0) {
        printf("ERROR: you should enter positive integers. Exiting...\n");
        return (EXIT_FAILURE);
    }

    if (m >= n) {
        printf("ERROR: the second integer should be greater than the first. "
                "Exiting...\n");
        return (EXIT_FAILURE);
    }

    int i, sum = 0;
    for (i = m; i <= n; i++) sum += i;
    printf("Sum: %d\n", sum);

    return (EXIT_SUCCESS);
}

