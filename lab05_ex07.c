/* 
 * File:   lab05_ex07.c
 * Author: riwakaram
 *
 * Created on November 10, 2021, 10:02 AM
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {

    if (argc != 2) {
        printf("ERROR: you should provide one argument. Exiting...\n");
        return (EXIT_FAILURE);
    }

    int n;
    if (sscanf(argv[1], "%d", &n) == 0) {
        printf("ERROR: you should enter an integer. Exiting...\n");
        return (EXIT_FAILURE);
    }

    if (n <= 0) {
        printf("ERROR: you should enter a positive integer. Exiting...\n");
        return (EXIT_FAILURE);
    }

    int i, sum = 0;
    for (i = 1; i <= n; i++) sum += i;
    printf("Sum: %d\n", sum);

    return (EXIT_SUCCESS);
}
