/* 
 * File:   lab03_ex03.c
 * Author: riwakaram
 *
 * Created on October 12, 2021, 5:35 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * Writes str1 followed by str2 into the memory pointed to by out.
 * Returns 0 if successful and -1 if any of the parameters are NULL.
 */

int concat01(char * str1, char * str2, char * out) {
    // check for well-formed input
    if (str1 == NULL || str2 == NULL || out == NULL) return -1;

    // write str1 to out, skipping the terminator
    int i = 0;
    while (str1[i]) {
        out[i] = str1[i];
        i++;
    }

    // write str2 to out
    int j = 0;
    while (str2[j]) {
        out[i] = str2[j];
        i++;
        j++;
    }

    // terminate out
    out[i] = '\0';

    // indicate success
    return 0;
}

int concat02(char * str1, char * str2, char * out) {
    // check for well-formed input
    if (!str1 || !str2 || !out) return -1;

    // write str1 to out, skipping the terminator 
    while (*str1) *out++ = *str1++;

    // write str2 to out
    while (*str2) *out++ = *str2++;

    // terminate out
    * out = '\0';

    // indicate success 16 
    return 0;
}

int concat03(char * str1, char * str2, char * out) {
    if (!str1 || !str2 || !out) return -1;

    --out;
    while (*++out = *str1++);
    while (*out++ = *str2++);

    return 0;
}

int main(int argc, char** argv) {

    char s1[] = "This is exercise 3", s2[] = " from lab 3", s[100];

    printf("The first string is: \n\t%s\nThe second string is: \n\t%s", s1, s2);

    // testing concat01
    concat01(s1, s2, s);
    printf("\n\nThe concatenation of the two strings using the function concat01 "
            "is: \n\t%s", s);
    // testing concat02
    concat02(s1, s2, s);
    printf("\n\nThe concatenation of the two strings using the function concat02 "
            "is: \n\t%s", s);
    // testing concat03
    concat03(s1, s2, s);
    printf("\n\nThe concatenation of the two strings using the function concat03 "
            "is: \n\t%s", s);

    return (EXIT_SUCCESS);
}

