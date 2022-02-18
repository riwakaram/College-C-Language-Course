/* 
 * File:   lab03_ex09.c
 * Author: riwakaram
 *
 * Created on October 12, 2021, 5:36 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * Returns whether str contains an instance of substr.
 * Returns 0 if either str or substr is NULL or substr is not in str;
 * returns 1 if substr is in str.
 */
int hasSubstring(char * str, char * substr) {
    // check for well-formed input
    if (!str || !substr) return 0;

    char *p = str, *q = substr;

    // finding the length of str and placing p at the end of str
    int n;
    for (n = 0; *p; p++, n++);

    // finding the length of substr and placing q at the end of substr
    int m;
    for (m = 0; *q; q++, m++);

    // if the supposed substring has a length greater or equal to that of the
    // string, no possibility of it being a substring.
    if (n <= m) return 0;

    char *temp = p;

    for (p = str; *p; p++) {
        q = substr;
        if ((*p == *q) && (m <= (temp - p))) {
            int count = 0;
            for (q = substr; *q; p++, q++) {
                if (*p != *q) {
                    p -= count;
                    break;
                } else {
                    count++;
                    if (count == m) return 1;
                }
            }
        }
    }

    return 0;
}

int main(int argc, char** argv) {

    char s1[] = "Hello universe!", s2[] = "lo", s3[] = "verse", s4[] = "verses",
            s5[] = "loun", s6[] = "erse!!", s7[] = "uni";

    printf("The first string is: \n\t%s", s1);
    printf("\nThe second string is: \n\t%s", s2);
    printf("\nThe third string is: \n\t%s", s3);
    printf("\nThe fourth string is: \n\t%s", s4);
    printf("\nThe fifth string is: \n\t%s", s5);
    printf("\nThe sixth string is: \n\t%s", s6);
    printf("\nThe seventh string is: \n\t%s", s7);

    printf("\n\nIs the second string a substring of the first? %s",
            (hasSubstring(s1, s2) == 1) ? "Yes" : "No");
    printf("\n\nIs the third string a substring of the first? %s",
            (hasSubstring(s1, s3) == 1) ? "Yes" : "No");
    printf("\n\nIs the fourth string a substring of the first? %s",
            (hasSubstring(s1, s4) == 1) ? "Yes" : "No");
    printf("\n\nIs the fifth string a substring of the first? %s",
            (hasSubstring(s1, s5) == 1) ? "Yes" : "No");
    printf("\n\nIs the sixth string a substring of the first? %s",
            (hasSubstring(s1, s6) == 1) ? "Yes" : "No");
    printf("\n\nIs the seventh string a substring of the first? %s\n",
            (hasSubstring(s1, s7) == 1) ? "Yes" : "No");

    return (EXIT_SUCCESS);
}
