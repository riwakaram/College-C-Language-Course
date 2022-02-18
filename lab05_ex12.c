/* 
 * File:   lab05_ex012.c
 * Author: riwakaram
 *
 * Created on November 10, 2021, 5:36 PM
 */

#include <stdio.h>
#include <stdlib.h>

void printUsage() {
    printf("Usage: rev [n] < [data file], where the file is a list of n "
            "integers \n");
}

int main(int argc, char** argv) {

    if (argc != 2) {
        // argument n not provided
        printUsage();
        return (EXIT_FAILURE);
    }

    int n;
    if (sscanf(argv[1], "%d", &n) != 1) {
        // the argument is not an integer
        printUsage();
        return (EXIT_FAILURE);
    }

    // variable-length array
    int nums[n];
    int i;
    for (i = 0; i < n; ++i) {
        // Tricky! Tell scanf to write the value directly
        // into the correct position of nums.
        int rc = scanf("%d", nums + i);
        if (rc == EOF) {
            printf("Unexpected end of file.\n");
            printUsage();
            return (EXIT_FAILURE);
        }
        if (rc == 0) {
            printf("Expected an integer.\n");
            printUsage();
            return (EXIT_FAILURE);
        }
    }

    // print the numbers in reverse
    for (i = n - 1; i >= 0; --i)
        printf("%d ", nums[i]);
    printf("\n");

    return (EXIT_SUCCESS);
}
