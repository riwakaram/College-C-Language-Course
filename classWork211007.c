/* 
 * File:   classWork211007.c
 * Author: riwakaram
 *
 * Created on October 7, 2021, 2:09 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * Write a function that returns the length of a string
 * Returns 0 if the string is NULL.
 */

/*
int len(char *s) {
    if (s == NULL) {
        return 0;
    }

    int n;
    for (n = 0; s[n] != '\0'; n++);

    return n;
}
 */

int len(char *s) {
    if (s == NULL) {
        return 0;
    }

    char *p;

    for (p = s; *p != '\0'; p++);

    return p - s;
}

/*
 * Write a function that concatenates two strings
 * s1 = "Good", s2 = " morning" ==> s = s1 + s2 = "Good morning"
 */
int concat(char *s1, char *s2, char *s) {
    if (!s1 || !s2 || !s) {
        return -1;
    }

    /*
        char *p = s1, *q = s;
        while (*p) {
     *q = *p;
            q++;
            p++;
        }

        p = s2;
        while (*p) {
     *q = *p;
            q++;
            p++;
        }
     */

    char *p, *q;
    for (p = s1, q = s; *p; *q++ = *p++);
    for (p = s2; *p; *q++ = *p++);
    *q = '\0';

    return 0;
}

int reverse(char *s) {
    if (!*s) {
        return -1;
    }

    // char *p = s + len(s) - 1;

    char *p = s;
    for (; *p; p++); // pointing at the null
    p--; // pointing at the last char

    while (p > s) {
        char t = *p;
        *p-- = *s;
        *s++ = t;
    }

    return 0;
}

int main(int argc, char** argv) {

    // char statement[] = "To be or not to be, that is the question!";
    // printf("The length of \n\t\"%s\"\n is %d", statement, len(statement));

    char word1[10] = "Hello", word2[10] = " world!", sentence[100];
    concat(word1, word2, sentence);
    printf("%s", sentence);

    return (EXIT_SUCCESS);
}

