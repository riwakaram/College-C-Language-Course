/* 
 * File:   lab05_ex17.c
 * Author: riwakaram
 *
 * Created on November 14, 2021, 10:00 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {

    int sum = 0;
    int cnt = 0;

    while (1) {
        char s[128];
        if (scanf("%s", s) == EOF) break;

        sum += strlen(s);
        cnt++;
    }

    printf("\nInteger mean: %d\n", sum / cnt);

    return (EXIT_SUCCESS);
}
