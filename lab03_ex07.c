/* 
 * File:   lab03_ex07.c
 * Author: riwakaram
 *
 * Created on October 12, 2021, 5:36 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * Returns whether str1 and str2 are equal.
 * Returns 0 if either str1 or str2 is NULL or if they are not equal;
 * returns 1 if they are equal
 */
int streq(char * str1, char * str2) {
    // check for well-formed input
    if (!str1 || !str2) return 0;

    char *p = str1, *q = str2;
    for (; *p; p++, q++) {
        if (*p != *q) {
            return 0;
        }
    }

    return 1;
}

int main(int argc, char** argv) {

    char s1[] = "Hello", s2[] = "Hello", s3[] = "Hulla";
    printf("The first word is: ""%s""\nThe second word is ""%s"""
            "\nThe third word is: ""%s""", s1, s2, s3);
    printf("\nAre the first and second words equal? %s",
            (streq(s1, s2) == 1) ? "Yes" : "No");
    printf("\nAre the first and third words equal? %s",
            (streq(s1, s3) == 1) ? "Yes" : "No");

    return (EXIT_SUCCESS);
}

