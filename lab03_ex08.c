/* 
 * File:   lab03_Ex08.c
 * Author: riwakaram
 *
 * Created on October 12, 2021, 5:36 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * Returns 0 if str or suf is NULL or if suf is not a suffix of str.
 * Otherwise returns 1.
 */
int suffix(char * str, char * suf) {
    // check for well-formed input
    if (!str || !suf) return 0;

    char *p = str, *q = suf;

    // finding the length of str and placing p at the end of str
    int n;
    for (n = 0; *p; p++, n++);

    // finding the length of suf and placing q at the end of suf
    int m;
    for (m = 0; *q; q++, m++);

    // if the supposed suffix has a length greater or equal to that of the
    // string, no possibility of it being a suffix
    if (n <= m) return 0;

    for (int i = m; i >= 0; i--, p--, q--) {
        if (*p != *q) return 0;
    }

    // indicate success
    return 1;
}

int main(int argc, char** argv) {

    char str[] = "Eating", suf1[] = "ing", suf2[] = "Eating",
            suf3[] = "Overeating";
    printf("The first word is: %s\nThe second word is: %s\nThe third word is: %s"
            "\nThe fourth word is: %s", str, suf1, suf2, suf3);
    printf("\n\nIs the second word a suffix of the first? %s",
            (suffix(str, suf1) == 1) ? "Yes" : "No");
    printf("\n\nIs the third word a suffix of the first? %s",
            (suffix(str, suf2) == 1) ? "Yes" : "No");
    printf("\n\nIs the third word a suffix of the first? %s",
            (suffix(str, suf3) == 1) ? "Yes" : "No");

    return (EXIT_SUCCESS);
}
