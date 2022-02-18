/* 
 * File:   classWork211026.c
 * Author: riwakaram
 *
 * Created on October 26, 2021, 3:15 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {

    char sentence[20][100] = {"Hello", "Balamand", "Good luck", "in the exam"};

    for (int i = 0; i < 4; i++) {
        printf("%s ", sentence[i]);
    }

    // print "luck"
    char *p = sentence[2];
    // printf("\n%s", &sentence[2][5]);
    printf("\n%s", p + 5);

    // char **q = sentence;
    // printf("\n%c", q[1][3]);

    char **q = &p;
    printf("\n%c", **q);

    return (EXIT_SUCCESS);
}

