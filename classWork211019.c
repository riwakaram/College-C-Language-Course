/* 
 * File:   classWork211019.c
 * Author: riwakaram
 *
 * Created on October 19, 2021, 12:51 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Command-line arguments
 */
int main(int argc, char** argv) {

    /*
     * argc: argument count
     * argv: argument values - double array of characters (array of strings)
     * 
     * Example:
     * cal 2022
     * "cal" is argv[0] => name of the application you're invoking
     * "2022" is argv[1] => first argument of the command
     */

    /*
        int i;
        for (i = 0; i < argc; i++) {
            printf("%s\n", argv[i]);
        }
     */

    /*
     * Write a program that reads a positive integer in the command line and
     * prints all positive numbers below this integer
     * Example: below 7
     *          1 2 3 4 5 6 
     */

    /*
        if (argc != 2) {
            printf("ERROR: you should provide an argument. Exiting...\n");
            return (EXIT_FAILURE);
        }

        int n;

        // sscanf returns the number of items successfully read
        if (sscanf(argv[1], "%d", &n) != 1) {
            printf("ERROR: you should provide an integer. Exiting...\n");
            return (EXIT_FAILURE);
        }
        if (n <= 0) {
            printf("ERROR: you should provide a positive integer. Exiting...\n");
            return (EXIT_FAILURE);
        }
        int i;
        for (i = 1; i < n; i++) {
            printf("%d ", i);
        }
     */

    /*
     * Write a program that reads words from the command line and prints the
     * word with the largest length
     * Example: largest_length Georges Ali Amine Alia Dominique
     *          Dominique 9
     */

    int i, l = 0, lo;
    for (i = 1; i < argc; i++) {
        if (strlen(argv[i]) > l) {
            l = strlen(argv[i]);
            lo = i;
        }
    }
    printf("%s %d\n", argv[lo], l);

    return (EXIT_SUCCESS);
}

