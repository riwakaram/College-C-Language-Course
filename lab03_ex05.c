/* 
 * File:   lab03_ex05.c
 * Author: riwakaram
 *
 * Created on October 12, 2021, 5:35 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * Copies at most n-1 characters of string in into the buffer pointed to by out.
 * If n is reached, returns -2. Otherwise, returns -1 for malformed input and 0
 * upon successful completion.
 */
int copyStringN(char * in, char * out, int n) {
    // check for well-formed input
    if (!in || !out || n <= 0) {
        return -1;
    }

    char *p = in, *q = out;
    int i;
    for (i = 0; i < (n - 1) && *p; i++) {
        *q++ = *p++;
    }
    *q = '\0';

    if (i == (n - 1)) return -2;

    // indicate success
    return 0;
}

int main(int argc, char** argv) {

    char s1[] = "Hello world!", s2[100];

    printf("The original string is: \n\t%s", s1);
    int r1 = copyStringN(s1, s2, 9);
    printf("\n\nCopying %d characters from s1 into s2 -> s2 is: \n\t%s", 9, s2);
    printf("\nThe return value is: %d", r1);

    int r2 = copyStringN(s1, s2, 30);
    printf("\n\nCopying %d characters from s1 into s2 -> s2 is: \n\t%s", 30, s2);
    printf("\nThe return value is: %d", r2);

    return (EXIT_SUCCESS);
}

