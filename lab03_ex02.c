/* 
 * File:   lab03_ex02.c
 * Author: riwakaram
 *
 * Created on October 12, 2021, 5:35 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * Returns the length of the string. Returns 0 if str is NULL and otherwise the
 * length of str.
 */

int strlen01(char * str) {
    if (str == NULL) return 0;

    int n = 0;
    while (str[n] != '\0') {
        n++;
    }

    return n;
}

int strlen02(char * str) {
    if (!str) return 0;

    int n = 0;
    while (str[n]) n++;

    return n;
}

int strlen03(char * str) {
    if (!str) return 0;

    int n;
    for (n = 0; str[n]; n++);

    return n;
}

int strlen04(char * str) {
    if (!str) return 0;

    int n;
    for (n = 0; *str; n++, str++);

    return n;
}

int strlen05(char * str) {
    if (!str) return 0;

    char * start = str;
    for (; *str; str++);

    return str - start;
}

int main(int argc, char** argv) {

    char s[] = "This is exercise 2 of lab 3 in the course CPEN220";
    printf("The string we need to find the length for is the following: "
            "\n\t%s", s);

    // testing strlen01
    printf("\n\nThe length of the string using strlen01 is: %d", strlen01(s));
    // testing strlen02
    printf("\nThe length of the string using strlen02 is: %d", strlen02(s));
    // testing strlen03
    printf("\nThe length of the string using strlen03 is: %d", strlen03(s));
    // testing strlen04
    printf("\nThe length of the string using strlen04 is: %d", strlen04(s));
    // testing strlen05
    printf("\nThe length of the string using strlen05 is: %d", strlen05(s));

    return (EXIT_SUCCESS);
}

