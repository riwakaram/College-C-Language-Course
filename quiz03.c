/* 
 * File:   quiz03.c
 * Author: riwakaram
 *
 * Created on October 19, 2021, 12:36 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * Zips together two strings into a third, alternating their characters.
 * Example: 
 *  s1: "whatever" (length 8)
 *  s2: "I am" (length 12)
 *      when zipped together, they form
 *  z: "wIhaamtever" (length 12)
 * 
 * Returns -1 if the input is malformed
 */
int stringzip(char *s1, char *s2, char *z) {
    // check for well-formed input
    if (!s1 || !s2 || !z) return -1;

    int lens1 = 0, lens2 = 0;

    char *p = s1, *q = s2;

    for (; *p; lens1++, p++); // length of s1
    for (; *q; lens2++, q++); // length of s2

    int lenz = lens1 + lens2; // length of z

    int i, j;
    for (i = 0, j = 0; i < lenz; i++, j += 2) {
        z[j] = s1[i];
        z[j + 1] = s2[i];
    }

    z[j] = '\0';

    // indicate success
    return 0;
}

int main(int argc, char** argv) {

    char quote1[] = "Whatever you do, do it well";
    char quote2[] = "Simplicity is the ultimate sophistication";

    char z[100];

    stringzip(quote1, quote2, z);

    printf("%s", z);

    return (EXIT_SUCCESS);
}

