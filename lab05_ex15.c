/* 
 * File:   lab05_ex15.c
 * Author: riwakaram
 *
 * Created on November 14, 2021, 5:50 PM
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {

    if (argc != 1) {
        printf("ERROR: you should provide one argument. Exiting...\n");
        return (EXIT_FAILURE);
    }

    char in;
    int countVowel[5] = {0};

    while (scanf("%c", &in) != EOF) {
        if (in == 'A' || in == 'a') countVowel[0]++;
        if (in == 'E' || in == 'e') countVowel[1]++;
        if (in == 'I' || in == 'i') countVowel[2]++;
        if (in == 'O' || in == 'o') countVowel[3]++;
        if (in == 'U' || in == 'u') countVowel[4]++;
    }

    printf("Count of A or a: %3d\n", countVowel[0]);
    printf("Count of E or e: %3d\n", countVowel[1]);
    printf("Count of I or i: %3d\n", countVowel[2]);
    printf("Count of O or o: %3d\n", countVowel[3]);
    printf("Count of U or u: %3d\n", countVowel[4]);

    return (EXIT_SUCCESS);
}
