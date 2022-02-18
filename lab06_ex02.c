/* 
 * File:   lab06_ex02.c
 * Author: riwakaram
 *
 * Created on November 25, 2021, 8:01 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {

    // 1. Obtain number of strings .
    if (argc != 2) {
        printf("Expected one integer argument.\n");
        return (EXIT_FAILURE);
    }

    int n;
    if (sscanf(argv[1], "%d", &n) != 1 || n <= 0) {
        printf("Expected a positive integer.\n");
        return (EXIT_FAILURE);
    }

    // 2. Read n strings.
    // Array of char *'s to hold strings.
    char ** strings = (char **) malloc(n * sizeof (char *));
    // Temporary buffer.
    char buf[128];

    int i;
    for (i = 0; i < n; i++) {
        // 2a. Scan for each string.
        if (scanf("%127s", buf) == EOF) {
            printf("Unexpected end of input.\n");
            return (EXIT_FAILURE);
        }
        // 2b. Allocate space to hold string permanently.
        // Notice the extra byte to hold the string terminator.
        strings[i] = (char *) malloc(strlen(buf) + 1);
        // 2c. Copy string from buffer to its space.
        strcpy(strings[i], buf);
    }

    // 3. Do something with strings. In this case, print.
    for (i = 0; i < n; ++i) {
        printf("%s\n", strings[i]);
    }

    // 4. Free allocated memory.
    for (i = 0; i < n; ++i) {
        free(strings[i]);
    }
    free(strings);

    return (EXIT_SUCCESS);
}
