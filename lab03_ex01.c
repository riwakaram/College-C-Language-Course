/* 
 * File:   lab03_ex01.c
 * Author: riwakaram
 *
 * Created on October 12, 2021, 5:35 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * Writes the message of msgIn into msgOut , except with all lowercase letters.
 * Returns 0 if successful and -1 if either of msgIn or msgOut is NULL.
 */
int whisper(char * msgIn, char * msgOut) {
    // check if input is well-formed
    if (!msgIn || !msgOut) {
        return -1;
    }

    char *p;
    p = msgIn; // pointer to msgIn

    while (*p) { // checking if *p is NULL, else continue
        if (*p >= 'A' && *p <= 'Z') {
            *msgOut = *p + ('a' - 'A'); // set to lowercase
        } else {
            *msgOut = *p;
        }
        p++;
        msgOut++;
    }

    *msgOut = '\0'; // terminate msgOut

    // indicate success
    return 0;
}

int main(int argc, char** argv) {

    char s1[] = "HeLlO wOrLd! HoW aRe YoU?", s2[100];
    printf("The original string is: \n\t%s", s1);
    whisper(s1, s2);
    printf("\nAfter calling the whisper function, the original string is: "
            "\n\t%s", s1);
    printf("\nAfter calling the whisper function, the lowercase string is: "
            "\n\t%s", s2);

    return (EXIT_SUCCESS);
}
