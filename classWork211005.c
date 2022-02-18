/* 
 * File:   classWork211005.c
 * Author: riwakaram
 *
 * Created on October 5, 2021, 2:00 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * C-Strings
 * a c-string is an array of characters (char) that are NULL-terminated
 */

/*
 * Write a function that capitalizes a string
 */
int capitalize(char *s) {
    if (!s) {
        return -1;
    }

    char *p;

    // for(p = s; *p != '\0'; p++)
    for (p = s; *p; p++) {
        if (*p >= 'a' && *p <= 'z') {
            *p -= 32; // or 0x20
        }
    }

    return 0;
}

int len(char *s) {
    if (!s) {
        return 0;
    }

    int counter = 0;

    while (*s) {
        counter++;
        s++;
    }

    return counter;
}

int main(int argc, char** argv) {

    /*
        char s[12] = "Hi there";

        printf("%s\n", s);

        char *p = s;

        while (*p != '\0') {
            printf("%c", *p);
            p++;
        }
        printf("\n");

        for (p = s; *p != '\0'; p++) {
            printf("%d (%x) ", *p, *p);
        }
     */

    char s[100] = "Hi there class of 2024";
    printf("%s\n", s);
    capitalize(s);
    printf("%s\n", s);
    // printf("%s\n", s + 3);

    printf("\nThe length of s is: %d", len(s));

    return (EXIT_SUCCESS);
}

