/* 
 * File:   lab05_ex18.c
 * Author: riwakaram
 *
 * Created on November 14, 2021, 10:09 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print(int len[33], int count) {
    if (!len) return;
    int i, j;

    printf("format: [# of letters] [percentage] [* representation]\n");

    for (i = 1; i < 33; i++) {
        int percent = (100 * len[i]) / count;
        printf("%2d %2d ", i, percent);

        for (j = 0; j < percent; j++) {
            printf("*");
        }
        printf("\n");
    }
}

int main(int argc, char** argv) {

    int i = 0, len[33] = {0}, count = 0;

    while (1) {
        char s[128];
        if (scanf("%s", s) == EOF) break;
        if (strlen(s) < 32) {
            len[strlen(s)]++;
        } else {
            len[32]++;
        }
        count++;
    }

    print(len, count);

    return (EXIT_SUCCESS);
}
