/* 
 * File:   lab03_ex10.c
 * Author: riwakaram
 *
 * Created on October 12, 2021, 5:36 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * Compares str1 and str2 according to "dictionary" (aka, "lexicographic") 
 * order, where characters are ordered by their ASCII values.
 * Returns -1 if str1 comes before str2; 0 if either str1 or str2 is NULL or 
 * if they are equal; and 1 if str1 comes after str2.
 */
int strcmp(char * str1, char * str2) {
    // check for well-formed input
    if (!str1 || !str2) return 0;

    char *p = str1, *q = str2;

    int lenStr1;
    char *pp = p;
    for (lenStr1 = 0; *pp; pp++, lenStr1++);

    int countEqual = 0;
    for (; *p || *q; p++, q++) {
        if (*p == *q) {
            countEqual++;
            if (countEqual == lenStr1) {
                return 0; // they are equal
            }
        } else if (*p > *q) {
            return 1; // str1 comes after str2
        } else if (*p < *q) {
            break;
        }
    }

    // str1 comes before str2
    return -1;
}

int main(int argc, char** argv) {

    char s1[] = "college", s2[] = "university", s3[] = "college",
            s4[] = "alumni", s5[] = "collage";
    
    printf("The first word is: \n\t%s", s1);
    printf("\nThe second word is: \n\t%s", s2);
    printf("\nThe third word is: \n\t%s", s3);
    printf("\nThe fourth word is: \n\t%s", s4);
    printf("\nThe fifth word is: \n\t%s", s5);
    
    printf("\n\nDoes the first word come before or after the second? %s",
            (strcmp(s1, s2) == 1) ? "After" : (strcmp(s1, s2) == -1) ?
            "Before" : "They are equal");
    printf("\n\nDoes the first word come before or after the third? %s",
            (strcmp(s1, s3) == 1) ? "After" : (strcmp(s1, s3) == -1) ?
            "Before" : "They are equal");
    printf("\n\nDoes the first word come before or after the fourth? %s",
            (strcmp(s1, s4) == 1) ? "After" : (strcmp(s1, s4) == -1) ?
            "Before" : "They are equal");
    printf("\n\nDoes the first word come before or after the fifth? %s",
            (strcmp(s1, s5) == 1) ? "After" : (strcmp(s1, s5) == -1) ?
            "Before" : "They are equal");

    return (EXIT_SUCCESS);
}

