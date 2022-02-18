/* 
 * File:   lab06_ex03.c
 * Author: riwakaram
 *
 * Created on November 25, 2021, 8:14 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {

    //Allocate initial array of char *'s to hold strings.
    int n = 1; // size of array
    char ** strings = (char **) malloc(n * sizeof (char*));

    int nstrings = 0; // number of strings read
    char buf[128];
    while (scanf("%127s", buf) != EOF) {
        // Is there space in strings for another string?
        if (nstrings == n) {
            // No, so double size of strings.
            n *= 2;
            strings = realloc(strings, n * sizeof (char *));
        }
        // Allocate space to hold string permanently.
        strings[nstrings] = (char *) malloc(strlen(buf) + 1);
        // Copy string from buffer to its space.
        strcpy(strings[nstrings], buf);
        // Increment the number of strings read.
        ++nstrings;
    }

    // Do something with strings. In this case, print.
    int i;
    for (i = 0; i < nstrings; ++i) {
        printf("%s\n", strings[i]);
    }

    // Free allocated memory.
    for (i = 0; i < nstrings; ++i) {
        free(strings[i]);
    }
    free(strings[i]);

    return (EXIT_SUCCESS);
}
