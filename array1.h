/* 
 * File:   array1.h
 * Author: riwakaram
 *
 * Created on September 30, 2021, 2:41 PM
 */

#ifndef ARRAY1_H
#define ARRAY1_H

#ifdef __cplusplus
extern "C" {
#endif

#include <time.h>
#include <stdio.h>

    /*
     * Write a function that takes two arrays and their sizes and 
     * copies one into another in reverse order
     * The function returns 0 if successful and -1 if a wrong input is provided
     */
    int copy_reversed(int *source, int *dest, int n) {
        if (!source || !dest || n <= 0) {
            return -1;
        }

        int i;

        for (i = 0; i < n; i++) {
            *(dest + n - i - 1) = *source;
            source++;
        }

        return 0;
    }

    /* 
     * Write a function that prints an integer array, ten on each line
     * The function returns 0 if successful and -1 if a wrong input is provided
     */
    int print_int_array(int a[], int n) {
        if (!a || n <= 0) {
            return -1;
        }

        int i;
        for (i = 0; i < n; i++) {
            printf("%4d", a[i]);
            if ((i + 1) % 10 == 0) {
                printf("\n");
            }
        }

        return 0;
    }

    /*
     * Write a function that takes an array of size n, and fill the array with
     * random numbers in the range [0, 999]
     * The function returns 0 if successful and -1 if a wrong input is provided
     */
    int random_int_array(int a[], int n) {
        if (!a || n <= 0) {
            return -1;
        }

        int i;
        for (i = 0; i < n; i++) {
            // rand returns a random integer in [0, 32767]
            a[i] = rand() % 1000;
        }

        return 0;
    }

    /*
     * Write a function that takes two integer arrays and zips them.
     * Example: a[4] = {1, 2, 3, 4}
     *          b[4] = {5, 6, 7, 8}
     *          z[8] = {1, 5, 2, 6, 3, 7, 4, 8}
     *
     * int zip(int *a, int *b, int *z, int n) {
     *     if (!a || !b || !z || n <= 0) {
     *         return -1;
     *     }
     * 
     *     for (int i = 0; i < n; i++) {
     *         z[2 * i] = a[i];
     *         z[2 * i + 1] = b[i];
     *     }
     * 
     *     return 0;
     * }
     * 
     * int zip(int *a, int *b, int *z, int n) {
     *     if (!a || !b || !z || n <= 0) {
     *         return -1;
     *     }
     * 
     *     for (int i = 0; i < n; i++{
     *          *z = *a;
     *          z++;
     *          *z = *b;
     *      }
     * 
     *      return 0;
     * }
     */
    int zip(int *a, int *b, int *z, int n) {
        if (!a || !b || !z || n <= 0) {
            return -1;
        }

        // int *pa = a, *pb = b, *pz = z;
        int *pa, *pb, *pz;

        for (pa = z, pb = b, pz = z; pa - a < n; pa++, pb++, pz++) {
            *pz = *pa;
            pz++;
            *pz = *pb;
        }

        return 0;
    }

#ifdef __cplusplus
}
#endif

#endif /* ARRAY1_H */

