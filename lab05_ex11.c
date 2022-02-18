/* 
 * File:   lab05_ex11.c
 * Author: riwakaram
 *
 * Created on November 10, 2021, 5:25 PM
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {

    int min, max;
    if (scanf("%d", &min) != 1) {
        printf("ERROR: you should enter an integer value. Exiting...\n");
        return EXIT_FAILURE;
    }

    max = min;

    int rc, val;
    while ((rc = scanf("%d", &val)) != EOF) {
        if (rc == 0) {
            printf("ERROR: you should enter an integer value. Exiting...\n");
            return EXIT_FAILURE;
        }
        if (val < min) {
            min = val;
        }
        if (val > max) {
            max = val;
        }
    }

    int range;
    range = max - min;
    printf("Range: %d\n", range);

    return (EXIT_SUCCESS);
}

