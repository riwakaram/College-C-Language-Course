/* 
 * File:   lab05_ex09.c
 * Author: riwakaram
 *
 * Created on November 10, 2021, 4:43 PM
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {

    int sum = 0;
    int cnt = 0;

    while (1) {
        // read an integer
        int num;
        int ret = scanf("%d", &num);
        // check if stdin has closed
        if (ret == EOF)
            // stdin has closed, so exit the loop
            break;
        // check if scanf returned 0, indicating bad input
        if (ret == 0) {
            printf("Expected an integer.\n");
            return (EXIT_FAILURE);
        }
        sum += num;
        cnt++;
    }

    printf("Sum: %d\nInteger mean: %d\n", sum, sum / cnt);

    return (EXIT_SUCCESS);
}

