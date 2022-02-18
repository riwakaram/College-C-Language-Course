/* 
 * File:   lab03_ex04.c
 * Author: riwakaram
 *
 * Created on October 12, 2021, 5:35 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * Copy string in into the buffer referenced by out.
 */

int copyString01(char * in, char * out) {
    if (!in || !out) return -1;

    while (*in) *out++ = *in++;
    *out = '\0';

    return 0;
}

int copyString02(char * in, char * out) {
    if (!in || !out) return -1;

    do {
        *out++ = *in++;
    } while (*in);

    return 0;
}

int copyString03(char * in, char * out) {
    if (!in || !out) return -1;

    int i = 0;
    while (in[i]) {
        out[i] = in[i];
        i++;
    }

    out[i] = '\0';

    return 0;
}

int main(int argc, char** argv) {

    char s1[] = "This is exercise 4 of lab 3", s2[100];

    printf("The string to copy is: \n\t%s", s1);

    // testing copyString01
    copyString01(s1, s2);
    printf("\n\nThe copied string using copyString01 is: \n\t%s", s2);
    // testing copyString02
    copyString02(s1, s2);
    printf("\n\nThe copied string using copyString02 is: \n\t%s", s2);
    // testing copyString03
    copyString03(s1, s2);
    printf("\n\nThe copied string using copyString03 is: \n\t%s", s2);

    return (EXIT_SUCCESS);
}

