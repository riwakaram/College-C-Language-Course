/* 
 * File:   quiz05.c
 * Author: riwakaram
 *
 * Created on November 16, 2021, 1:56 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printUsage() {
    printf("USAGE: shift [-l] [-r] num n\n");
}

int main(int argc, char** argv) {

    if (argc != 4) {
        printUsage();
        return (EXIT_FAILURE);
    }

    if (strcmp(argv[1], "-l") != 0 && strcmp(argv[1], "-r") != 0) {
        printf("ERROR: the argument provided should be either -l for left "
                "or -r for right. Exiting...\n");
        printUsage();
        return (EXIT_FAILURE);
    }

    int n, m;
    if (sscanf(argv[2], "%d", &n) == 0 || sscanf(argv[3], "%d", &m) == 0) {
        printf("ERROR: you should enter an integer. Exiting...\n");
        printUsage();
        return (EXIT_FAILURE);
    }

    if (m < 0) {
        printf("ERROR: you should enter a positive integer. Exiting...\n");
        printUsage();
        return (EXIT_FAILURE);
    }

    if (strcmp(argv[1], "-l") == 0) {
        printf("%d", (n << m));
    } else {
        printf("%d", (n >> m));
    }
    printf("\n");

    return (EXIT_SUCCESS);
}
