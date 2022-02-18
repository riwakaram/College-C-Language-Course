/* 
 * File:   lab05_ex10.c
 * Author: riwakaram
 *
 * Created on November 10, 2021, 5:08 PM
 */

#include <stdio.h>
#include <stdlib.h>

void printUsage() {
    printf("Usage: min < [data file], where the file is a nonempty list of "
            "integers\n");
}

int main(int argc, char** argv) {

    int min;
    // 1. obtain the first value as min
    if (scanf("%d", &min) != 1) {
        // either empty file or not an integer
        printUsage();
        return EXIT_FAILURE;
    }

    // 2. scan the rest
    // A busy line of code:
    //  a. call scanf, requesting to scan for an integer that should be written 
    //     to val
    //  b. set rc to the return code (EOF, 0, or 1)
    //          EOF - End Of File
    //            0 - did not match an integer
    //            1 - matched an integer
    // c. check if the return code is (not) EOF
    int rc, val;
    while ((rc = scanf("%d", &val)) != EOF) {
        // not EOF, but it might be 0
        if (rc == 0) {
            // bad data
            printUsage();
            return EXIT_FAILURE;
        }
        // good data
        if (val < min) {
            min = val;
        }
    }

    // 3. report the min
    printf("Min: %d\n", min);

    return (EXIT_SUCCESS);
}

