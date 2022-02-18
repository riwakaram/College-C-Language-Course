/* 
 * File:   lab05_ex16.c
 * Author: riwakaram
 *
 * Created on November 14, 2021, 7:18 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * This function encrypts a string
 * Returns -1 for invalid input and 0 for success
 */
int encrypt(char *s) {
    // check for invalid input
    if (!s) return -1;

    char *p;
    for (p = s; *p; p++) {
        if (*p >= 'a' && *p <= 'z') {
            *p += 3;
            if (*p > 'z') *p -= ('z' - 'a' + 1);
        } else if (*p >= 'A' && *p <= 'Z') {
            *p += 3;
            if (*p > 'Z') *p -= ('Z' - 'A' + 1);
        }
    }

    // indicate success
    return 0;
}

/*
 * This function decrypts a string
 * Returns -1 for invalid input and 0 for success
 */
int decrypt(char *s) {
    // check for invalid input
    if (!s) return -1;

    char *p;
    for (p = s; *p; p++) {
        if (*p >= 'a' && *p <= 'z') {
            *p -= 3;
            if (*p < 'a') *p += ('z' - 'a' + 1);
        } else if (*p >= 'A' && *p <= 'Z') {
            *p -= 3;
            if (*p < 'A') *p += ('Z' - 'A' + 1);
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

    if (strcmp(argv[1], "-encrypt") != 0 && strcmp(argv[1], "-decrypt") != 0) {
        printf("ERROR: the argument provided should be either -encrypt or "
                "-decrypt. Exiting...\n");
        return (EXIT_FAILURE);
    }

    char in[128];

    if (strcmp(argv[1], "-encrypt") == 0) {
        while (scanf("%s", in) != EOF) {
            encrypt(in);
            printf("%s ", in);
        }
    } else {
        while (scanf("%s", in) != EOF) {
            decrypt(in);
            printf("%s ", in);
        }
    }
    printf("\n");

    return (EXIT_SUCCESS);
}
