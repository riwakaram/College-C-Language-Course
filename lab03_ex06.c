/* 
 * File:   lab03_ex06.c
 * Author: riwakaram
 *
 * Created on October 12, 2021, 5:36 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * Removes all vowels from string in and writes the result to out.
 * Returns 0 if successful and -1 if either in or out is NULL.
 */
int xvowelize(char * in, char * out) {
    // check for well-formed input
    if (!in || !out) return -1;

    char *p = in;
    while (*p) {
        if ((*p != 'a') &&
                (*p != 'e') &&
                (*p != 'i') &&
                (*p != 'o') &&
                (*p != 'u')) {
            *out++ = *p++;
        } else {
            p++;
        }
    }

    *out = '\0';

    return 0;
}

int main(int argc, char** argv) {

    char s1[] = "This is a programming for engineers course", s2[100];
    printf("The original string is: \n\t%s", s1);
    xvowelize(s1, s2);
    printf("\n\nThe original string after xvowelize is: \n\t%s", s1);
    printf("\n\nThe vowelized string is: \n\t%s", s2);

    return (EXIT_SUCCESS);
}

