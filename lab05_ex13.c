/* 
 * File:   lab05_ex13.c
 * Author: riwakaram
 *
 * Created on November 14, 2021, 1:48 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * This function capitalizes a string
 * Returns -1 for invalid input and 0 for success
 */
int shout(char *s) {
    // check for invalid input
    if (!s) return -1;

    char *p;
    for (p = s; *p; p++) {
        if (*p >= 'a' && *p <= 'z') {
            *p -= 32;
        }
    }

    // indicate success
    return 0;
}

/*
 * This function uncapitalizes a string
 * Returns -1 for invalid input and 0 for success
 */
int whisper(char *s) {
    // check for invalid input
    if (!s) return -1;

    char *p;
    for (p = s; *p; p++) {
        if (*p >= 'A' && *p <= 'Z') {
            *p += 32;
        }
    }

    // indicate success
    return 0;
}

int main(int argc, char** argv) {

    if (argc != 2) {
        printf("ERROR: you should provide two arguments. Exiting...\n");
        return (EXIT_FAILURE);
    }

    if (strcmp(argv[1], "-s") != 0 && strcmp(argv[1], "-w") != 0) {
        printf("ERROR: the argument provided should be either -s for shout "
                "or -w for whisper. Exiting...\n");
        return (EXIT_FAILURE);
    }

    char in[128];

    if (strcmp(argv[1], "-s") == 0) {
        while (scanf("%s", in) != EOF) {
            shout(in);
            printf("%s ", in);
        }
    } else {
        while (scanf("%s", in) != EOF) {
            whisper(in);
            printf("%s ", in);
        }
    }
    printf("\n");

    return (EXIT_SUCCESS);
}
